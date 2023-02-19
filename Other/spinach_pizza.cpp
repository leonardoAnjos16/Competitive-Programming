#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<int, int> operator -(pair<int, int> a, pair<int, int> b) {
    return make_pair(b.first - a.first, b.second - a.second);
}

llong operator *(pair<int, int> a, pair<int, int> b) {
    return 1LL * a.first * b.second - 1LL * a.second * b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertices[i] = make_pair(x, y);
    }

    if (n & 1) cout << "Beatrice\n";
    else cout << "Alberto\n";

    cout.flush();

    vector<bool> chosen(n, false);
    if (n & 1) {
        int q; cin >> q;
        chosen[q - 1] = true;
    }

    for (int i = n % 2; i < n - 2; i += 2) {
        llong mn = LLONG_MAX, p = -1;
        for (int j = 0; j < n; j++)
            if (!chosen[j]) {
                int l = (j - 1 + n) % n;
                while (chosen[l]) l = (l - 1 + n) % n;

                int r = (j + 1) % n;
                while (chosen[r]) r = (r + 1) % n;

                pair<int, int> u = vertices[r] - vertices[j];
                pair<int, int> v = vertices[l] - vertices[j];
                llong area = abs(u * v);

                if (area < mn) {
                    p = j;
                    mn = area;
                }
            }

        chosen[p] = true;

        cout << (p + 1) << "\n";
        cout.flush();

        int q; cin >> q;
        chosen[q - 1] = true;
    }
}