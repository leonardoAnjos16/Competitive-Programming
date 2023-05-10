#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> v[i];

    if (n == 1) cout << "1\n";
    else {
        int ans = 2;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int any_time = 0;
                map<pair<llong, llong>, int> cnt;

                for (int k = j + 1; k < n; k++) {
                    llong nt = 1LL * (j - i) * (s[k] - s[j]) - 1LL * (k - j) * (s[j] - s[i]);
                    llong dt = 1LL * (k - j) * (v[j] - v[i]) - 1LL * (j - i) * (v[k] - v[j]);

                    if (!nt && !dt) any_time++;
                    else if (dt) {
                        llong g = gcd(abs(nt), abs(dt));
                        nt /= g; dt /= g;

                        if (!nt) dt = 1;
                        else if (nt < 0 && dt < 0) nt = -nt, dt = -dt;
                        else if (dt < 0) nt = -nt, dt = -dt;

                        if (nt < 0) continue;

                        pair<llong, llong> t = make_pair(nt, dt);
                        cnt[t]++;
                    }
                }

                ans = max(ans, any_time + 2);
                for (auto [t, c]: cnt)
                    ans = max(ans, c + any_time + 2);
            }

        cout << ans << "\n";
    }
}