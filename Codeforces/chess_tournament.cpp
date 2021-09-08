#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<string> ans(n, string(n, 'X'));
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    ans[i][j] = ans[j][i] = '=';
                }

        bool possible = true;
        for (int i = 0; i < n && possible; i++)
            if (s[i] == '2') {
                possible = false;
                for (int j = 0; j < n && !possible; j++)
                    if (ans[i][j] == '+') possible = true;

                for (int j = 0; j < n && !possible; j++) {
                    if (i == j) continue;
                    if (ans[i][j] == 'X') {
                        possible = true;
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                    }
                }

                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (ans[i][j] == 'X') {
                        ans[i][j] = '-';
                        ans[j][i] = '+';
                    }
                }
            }

        if (!possible) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto s: ans)
                cout << s << "\n";
        }
    }
}