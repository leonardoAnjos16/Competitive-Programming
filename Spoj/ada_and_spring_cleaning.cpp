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
    ans.fst = (ans.fst - (hash[l - 1].fst * powers[r - l + 1].fst % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - (hash[l - 1].snd * powers[r - l + 1].snd % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    powers.assign(1, { 1, 1 });
    for (int i = 1; i < MAX; i++)
        powers.pb({ (powers[i - 1].fst * B) % MOD_1, (powers[i - 1].snd * B) % MOD_2 });

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        string s; cin >> s;

        vector<pll> hash(1, { s[0], s[0] });
        for (int i = 1; i < N; i++)
            hash.pb({ (hash[i - 1].fst * B + s[i]) % MOD_1, (hash[i - 1].snd * B + s[i]) % MOD_2 });

        set<pll> hashes;
        for (int i = K - 1; i < N; i++)
            hashes.insert(get_hashes(hash, i - K + 1, i));

        int ans = size(hashes);
        cout << ans << "\n";
    }
}