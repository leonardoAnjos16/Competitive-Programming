#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int B = 253;
const int MAX = 2e3 + 5;
const int MOD = 1e9 + 7;

vector<long> h, p;

long get_hash(int l, int r) {
    if (!l) return h[r];
    return (h[r] - ((h[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p.assign(MAX, 1LL);
    for (int i = 1; i < MAX; i++)
        p[i] = (p[i - 1] * B) % MOD;

    int T; cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        h.resize(s.size());
        h[0] = s[0];

        for (int i = 1; i < (int) s.size(); i++)
            h[i] = (h[i - 1] * B + s[i]) % MOD;

        long t_hash = t[0];
        for (int i = 1; i < (int) t.size(); i++)
            t_hash = (t_hash * B + t[i]) % MOD;

        vector<int> ans;
        for (int i = t.size() - 1; i < (int) s.size(); i++)
            if (get_hash(i - (int) t.size() + 1, i) == t_hash)
                ans.push_back(i - (int) t.size() + 2);

        for (int i = 0; i < (int) ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}