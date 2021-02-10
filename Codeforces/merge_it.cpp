#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int cnt[3] = {0};
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a % 3]++;
        }

        int ans = cnt[0];

        int aux = min(cnt[1], cnt[2]);
        ans += aux;

        ans += (cnt[1] - aux) / 3;
        ans += (cnt[2] - aux) / 3;
        
        cout << ans << "\n";
    }
}