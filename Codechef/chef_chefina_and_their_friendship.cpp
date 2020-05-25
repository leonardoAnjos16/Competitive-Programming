#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int n = S.size();

        int ans = 0;
        for (int i = 2; i < n; i += 2)
            if (S.substr(0, i / 2) == S.substr(i / 2, i / 2) &&
                S.substr(i, (n - i) / 2) == S.substr((n + i) / 2, (n - i) / 2))
                ans++;

        cout << ans << "\n";
    }
}