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

const int BASE = 257;
const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<long> powers(1, 1);

int get_hash(vector<long> &hash, int l, int r) {
    if (!l) return hash[r];
    return (hash[r] - ((hash[l - 1] * powers[r - l + 1]) % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string ans; cin >> ans;

    vector<long> hash(1, ans[0]);
    for (int i = 1; i < size(ans); i++) {
        hash.pb((hash[i - 1] * BASE + ans[i]) % MOD);
        powers.pb((powers[i - 1] * BASE) % MOD);
    }

    for (int i = 1; i < n; i++) {
        string s; cin >> s;

        vector<long> new_hash(1, s[0]);
        for (int j = 1; j < size(s); j++)
            new_hash.pb((new_hash[j - 1] * BASE + s[j]) % MOD);

        int aux = min(size(ans), size(s)), idx = aux - 1;
        while (idx >= 0 && get_hash(hash, size(ans) - idx - 1, size(ans) - 1) != get_hash(new_hash, 0, idx)) idx--;

        string extra = s.substr(idx + 1);
        for (char c: extra) {
            hash.pb((hash[size(hash) - 1] * BASE + c) % MOD);
            powers.pb((powers[size(powers) - 1] * BASE) % MOD);
        }

        ans += extra;
    }

    cout << ans << "\n";
}