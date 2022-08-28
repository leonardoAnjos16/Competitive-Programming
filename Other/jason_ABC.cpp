#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string S; cin >> S;

    vector<int> as(3 * n + 1, 0), bs(3 * n + 1, 0), cs(3 * n + 1, 0);
    for (int i = 1; i <= 3 * n; i++) {
        as[i] = as[i - 1];
        bs[i] = bs[i - 1];
        cs[i] = cs[i - 1];

        if (S[i - 1] == 'A') as[i]++;
        else if (S[i - 1] == 'B') bs[i]++;
        else cs[i]++;
    }

    if (as[3 * n] == n && bs[3 * n] == n) {
        cout << "0\n";
        return 0;
    }

    map<tuple<int, int, int>, int> to_a, to_b, to_c;
    tuple<int, int, int> aux = make_tuple(0, 0, 0);
    to_a[aux] = to_b[aux] = to_c[aux] = 1;

    int l = -1, r = -1; char c = '-';
    for (int i = 1; i <= 3 * n && l == -1; i++) {
        tuple<int, int, int> aux = make_tuple(n - as[3 * n] + as[i] - i, n - bs[3 * n] + bs[i], n - cs[3 * n] + cs[i]);
        if (to_a.count(aux)) l = to_a[aux], r = i, c = 'A';
        to_a[make_tuple(as[i] - i, bs[i], cs[i])] = i + 1;

        aux = make_tuple(n - as[3 * n] + as[i], n - bs[3 * n] + bs[i] - i, n - cs[3 * n] + cs[i]);
        if (to_b.count(aux)) l = to_b[aux], r = i, c = 'B';
        to_b[make_tuple(as[i], bs[i] - i, cs[i])] = i + 1;

        aux = make_tuple(n - as[3 * n] + as[i], n - bs[3 * n] + bs[i], n - cs[3 * n] + cs[i] - i);
        if (to_c.count(aux)) l = to_c[aux], r = i, c = 'C';
        to_c[make_tuple(as[i], bs[i], cs[i] - i)] = i + 1;
    }

    if (l != -1) {
        cout << "1\n" << l << " " << r << " " << c << "\n";
        return 0;
    }

    int idx = 1;
    while (idx <= 3 * n && as[idx] < n && bs[idx] < n && cs[idx] < n) idx++;

    cout << "2\n";
    if (as[idx] == n) {
        int size = n - bs[idx];
        cout << (idx + 1) << " " << (idx + size) << " B\n";
        cout << (idx + size + 1) << " " << (3 * n) << " C\n";
    } else if (bs[idx] == n) {
        int size = n - as[idx];
        cout << (idx + 1) << " " << (idx + size) << " A\n";
        cout << (idx + size + 1) << " " << (3 * n) << " C\n";
    } else {
        int size = n - as[idx];
        cout << (idx + 1) << " " << (idx + size) << " A\n";
        cout << (idx + size + 1) << " " << (3 * n) << " B\n";
    }
}