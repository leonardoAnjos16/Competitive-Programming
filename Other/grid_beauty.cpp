#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            map<int, int> ncnt;
            for (int j = 0; j < m; j++) {
                int a; cin >> a;
                if (--cnt[a] >= 0) ans++;
                ncnt[a]++;
            }

            cnt = ncnt;
        }

        cout << ans << "\n";
    }
}