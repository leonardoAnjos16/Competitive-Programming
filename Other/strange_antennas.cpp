#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("J.in", "r", stdin);

    int n; cin >> n;
    int a; cin >> a;

    vector<map<int, int>> cnt(n, map<int, int>());
    for (int i = 0; i < a; i++) {
        int r, c, p, o;
        cin >> r >> c >> p >> o;

        if (o > 1) r--;
        if (o == 0 || o == 3) c--;
        if (r < 0 || c < 0) continue;

        for (int j = r; j >= 0 && j < n && p > 0; j += (o < 2 ? 1 : -1), p--) {
            int begin = o > 0 && o < 3 ? c : max(c - p + 1, 0);
            if (begin < n) cnt[j][begin]++;

            int end = o > 0 && o < 3 ? c + p : c + 1;
            if (end < n) cnt[j][end]--;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int last = 0; long sum = 0LL;
        for (auto p: cnt[i]) {
            if (sum & 1LL) ans += p.first - last;
            last = p.first; sum += p.second;
        }

        if (sum & 1LL) ans += n - last;
    }

    cout << ans << "\n";
}