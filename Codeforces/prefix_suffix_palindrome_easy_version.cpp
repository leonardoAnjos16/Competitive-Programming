#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int B = 257;
const int MAX = 5e3 + 5;
const int MOD_1 = 1e9 + 7;
const int MOD_2 = 1e9 + 9;

vector<pll> h, rh, p;

pll get_hashes(int l, int r) {
    if (!l) return h[r];

    pll ans = h[r];
    ans.fst = (ans.fst - ((h[l - 1].fst * p[r - l + 1].fst) % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - ((h[l - 1].snd * p[r - l + 1].snd) % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

pll get_rev_hashes(int l, int r) {
    if (r == size(rh) - 1) return rh[l];

    pll ans = rh[l];
    ans.fst = (ans.fst - ((rh[r + 1].fst * p[r - l + 1].fst) % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - ((rh[r + 1].snd * p[r - l + 1].snd) % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p.assign(1, { 1LL, 1LL });
    for (int i = 1; i < MAX; i++)
        p.pb({ (p[i - 1].fst * B) % MOD_1, (p[i - 1].snd * B) % MOD_2 });

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        h.resize(size(s)); h[0] = { s[0], s[0] };
        for (int i = 1; i < size(s); i++)
            h[i] = { (h[i - 1].fst * B + s[i]) % MOD_1, (h[i - 1].snd * B + s[i]) % MOD_2 };

        rh.resize(size(s)); rh[size(s) - 1] = { s[size(s) - 1], s[size(s) - 1] };
        for (int i = size(s) - 2; i >= 0; i--)
            rh[i] = { (rh[i + 1].fst * B + s[i]) % MOD_1, (rh[i + 1].snd * B + s[i]) % MOD_2 };

        string all_prefix = "";
        for (int i = size(s); i > 0 && all_prefix == ""; i--)
            if (get_hashes(0, i - 1) == get_rev_hashes(0, i - 1))
                all_prefix = s.substr(0, i);

        string all_suffix = "";
        for (int i = size(s); i > 0 && all_suffix == ""; i--)
            if (get_hashes(size(s) - i, size(s) - 1) == get_rev_hashes(size(s) - i, size(s) - 1))
                all_suffix = s.substr(size(s) - i);

        int idx = 0;
        while (idx < size(s) / 2 && get_hashes(0, idx) == get_rev_hashes(size(s) - idx - 1, size(s) - 1)) idx++;

        string more_prefix = "", more_suffix = "";
        if (--idx >= 0) {
            for (int i = size(s) - 2 * (idx + 1); i > 0 && more_prefix == ""; i--)
                if (get_hashes(idx + 1, idx + i) == get_rev_hashes(idx + 1, idx + i))
                    more_prefix = s.substr(0, idx + 1) + s.substr(idx + 1, i) + s.substr(size(s) - idx - 1);

            for (int i = size(s) - 2 * (idx + 1); i > 0 && more_suffix == ""; i--)
                if (get_hashes(size(s) - idx - i - 1, size(s) - idx - 2) == get_rev_hashes(size(s) - idx - i - 1, size(s) - idx - 2))
                    more_suffix = s.substr(0, idx + 1) + s.substr(size(s) - idx - i - 1, i) + s.substr(size(s) - idx - 1);
        }

        string ans = all_prefix;
        if (size(all_suffix) > size(ans)) ans = all_suffix;
        if (size(more_prefix) > size(ans)) ans = more_prefix;
        if (size(more_suffix) > size(ans)) ans = more_suffix;

        cout << ans << "\n";
    }
}