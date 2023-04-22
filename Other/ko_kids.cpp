#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s; cin >> s;

    int ans = 0, know = 0;
    for (int i = 0; i < k; i++) {
        while (know < n) {
            if ((!know || s[know - 1] == 'R') && s[know] == 'R') break;
            if (s[know - 1] == 'L' && s[know] == 'L') break;
            know++;
        }

        if (know++ >= n) ans++;
    }

    cout << ans << "\n";
}