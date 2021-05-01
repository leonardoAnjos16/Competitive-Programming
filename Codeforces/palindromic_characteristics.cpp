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
vector<vi> memo;

pll get_hashes(int l, int r) {
    if (!l) return h[r];

    pll ans = { h[r].fst, h[r].snd };
    ans.fst = (ans.fst - ((h[l - 1].fst * p[r - l + 1].fst) % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - ((h[l - 1].snd * p[r - l + 1].snd) % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

pll get_rev_hashes(int l, int r) {
    if (r == size(rh) - 1) return rh[l];

    pll ans = { rh[l].fst, rh[l].snd };
    ans.fst = (ans.fst - ((rh[r + 1].fst * p[r - l + 1].fst) % MOD_1) + MOD_1) % MOD_1;
    ans.snd = (ans.snd - ((rh[r + 1].snd * p[r - l + 1].snd) % MOD_2) + MOD_2) % MOD_2;

    return ans;
}

bool palindrome(int l, int r) {
    return get_hashes(l, r) == get_rev_hashes(l, r);
}

int how_much_palindromic(int l, int r) {
    if (l == r) return 1;

    int &ans = memo[l][r - l];
    if (~ans) return ans;

    int half = (r - l + 1) / 2;
    if (get_hashes(l, l + half - 1) != get_hashes(r - half + 1, r))
        return ans = palindrome(l, r) ? 1 : 0;

    int child = how_much_palindromic(l, l + half - 1);
    return ans = !child ? 0 : child + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p.assign(1, { 1LL, 1LL });
    for (int i = 1; i < MAX; i++)
        p.pb({ (p[i - 1].fst * B) % MOD_1, (p[i - 1].snd * B) % MOD_2 });

    string s; cin >> s;

    memo.resize(size(s));
    for (int i = 0; i < size(s); i++)
        memo[i].assign(size(s) - i, -1);

    h.resize(size(s)); h[0] = { s[0], s[0] };
    for (int i = 1; i < size(s); i++)
        h[i] = { (h[i - 1].fst * B + s[i]) % MOD_1, (h[i - 1].snd * B + s[i]) % MOD_2 };

    rh.resize(size(s)); rh[size(s) - 1] = { s[size(s) - 1], s[size(s) - 1] };
    for (int i = size(s) - 2; i >= 0; i--)
        rh[i] = { (rh[i + 1].fst * B + s[i]) % MOD_1, (rh[i + 1].snd * B + s[i]) % MOD_2 };

    int ans[MAX] = {0LL};
    for (int i = 0; i < size(s); i++)
        for (int j = i; j < size(s); j++) {
            int aux = how_much_palindromic(i, j);
            if (aux) ans[aux - 1]++;
        }

    for (int i = size(s) - 2; i >= 0; i--)
        ans[i] += ans[i + 1];

    for (int i = 0; i < size(s); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}