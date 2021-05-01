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
const int MAX = 1e5 + 5;
const int MOD_1 = 1e9 + 7;
const int MOD_2 = 1e9 + 9;

vector<pll> powers;

pll get_hashes(vector<pll> &hash, int l, int r) {
    if (!l) return hash[r];

    pll ans = { hash[r].fst, hash[r].snd };
    ans.fst = (ans.fst - ((hash[l - 1].fst * powers[r - l + 1].fst) % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - ((hash[l - 1].snd * powers[r - l + 1].snd) % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    powers.assign(1, { 1LL, 1LL });
    for (int i = 1; i < MAX; i++)
        powers.pb({ (powers[i - 1].fst * B) % MOD_1, (powers[i - 1].snd * B) % MOD_2 });

    string s[3];
    while (cin >> s[0] >> s[1] >> s[2]) {
        vector<vector<pll>> hashes(3);
        for (int i = 0; i < 3; i++) {
            hashes[i] = vector<pll>(1, { s[i][0], s[i][0] });
            for (int j = 1; j < size(s[i]); j++)
                hashes[i].pb({ (hashes[i][j - 1].fst * B + s[i][j]) % MOD_1, (hashes[i][j - 1].snd * B + s[i][j]) % MOD_2 });
        }

        int ans = INT_MAX, order[3] = { 0, 1, 2 };
        do {
            string curr = s[order[0]];
            vector<pll> hash = hashes[order[0]];

            for (int i = 1; i < 3; i++) {
                int l = 0;
                bool done = false;

                while (l < size(curr) && !done) {
                    int r = min(l + size(s[order[i]]), size(curr)) - 1;
                    if (get_hashes(hash, l, r) != get_hashes(hashes[order[i]], 0, r - l)) l++;
                    else done = true;
                }

                int r = min(l + size(s[order[i]]), size(curr)) - 1;
                string extra = s[order[i]].substr(r - l + 1);

                for (char c: extra)
                    hash.pb({ (hash[size(hash) - 1].fst * B + c) % MOD_1, (hash[size(hash) - 1].snd * B + c) % MOD_2 });

                curr += extra;
            }

            ans = min(ans, size(curr));
        } while (next_permutation(order, order + 3));

        cout << ans << "\n";
    }
}