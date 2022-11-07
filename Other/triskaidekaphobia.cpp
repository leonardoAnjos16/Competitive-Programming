#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s; cin >> s;
    int n = s.size();

    int ans = INT_MAX;
    for (int i = -1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j <= i && s[j] == '1') cnt++;
            else if (j > i && s[j] == '3') cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans << "\n";
}