#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;

        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) {
            cin >> r[i].first;
            r[i].second = i;
        }

        sort(r.rbegin(), r.rend());

        int k = 0;
        vector<int> a, b;

        for (int i = 0; i < n; i++) {
            if ((k + 1) * s1 < (i - k + 1) * s2) a.push_back(r[i].second + 1), k++;
            else b.push_back(r[i].second + 1);
        }

        cout << k;
        for (int i = 0; i < k; i++)
            cout << " " << a[i];

        cout << "\n";

        cout << (n - k);
        for (int i = 0; i < n - k; i++)
            cout << " " << b[i];

        cout << "\n";
    }
}