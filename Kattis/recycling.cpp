#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> aux;
    vector<int> left(n, -1);

    for (int i = 0; i < n; i++) {
        while (!aux.empty() && a[aux.top()] >= a[i])
            aux.pop();

        if (!aux.empty()) left[i] = aux.top();
        aux.push(i);
    }

    while (!aux.empty()) aux.pop();

    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!aux.empty() && a[aux.top()] >= a[i])
            aux.pop();

        if (!aux.empty()) right[i] = aux.top();
        aux.push(i);
    }

    tuple<llong, int, int> ans = make_tuple(LLONG_MIN, -1, -1);
    for (int i = 0; i < n; i++) {
        int s = left[i] + 1;
        int e = right[i] - 1;
        ans = max(ans, make_tuple((e - s + 1LL) * a[i], -s, e));
    }

    llong r; int s, e;
    tie(r, s, e) = ans;
    cout << (-s + 1) << " " << (e + 1) << " " << r << "\n";
}