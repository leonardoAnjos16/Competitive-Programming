#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        vector<int> f(n);
        for (int i = 0; i < n; i++)
            cin >> f[i];

        int time = 0;
        vector<int> d(n);

        for (int i = 0; i < n; i++) {
            int start = max(s[i], time);
            d[i] = f[i] - start;
            time = f[i];
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << d[i];
        }

        cout << "\n";
    }
}