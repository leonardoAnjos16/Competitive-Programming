#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(k, 0);
        for (int i = 0; i < k; i++)
            cin >> x[i];

        vector<int> c(k, 0);
        for (int i = 0; i < k; i++)
            cin >> c[i];

        if (c[0] > x[0]) cout << "NO\n";
        else {
            char nxt = 'a';
            string ans = "";

            for (int i = 0; i < c[0] - 3; i++)
                ans += 'a';

            while ((int) ans.size() < x[0]) {
                ans += nxt;
                nxt = 'a' + (nxt - 'a' + 1) % 3;
            }

            bool possible = true;
            for (int i = 1; i < k && possible; i++) {
                if (c[i] - c[i - 1] > x[i] - x[i - 1]) possible = false;
                else {
                    char ch = 'd' + i - 1;
                    for (int j = 0; j < c[i] - c[i - 1]; j++)
                        ans += ch;

                    while ((int) ans.size() < x[i]) {
                        ans += nxt;
                        nxt = 'a' + (nxt - 'a' + 1) % 3;
                    }
                }
            }

            if (!possible) cout << "NO\n";
            else {
                cout << "YES\n";
                cout << ans << "\n";
            }
        }
    }
}