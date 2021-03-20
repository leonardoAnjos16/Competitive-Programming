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

const int MAX = 2e5 + 5;

string s;
vector<vector<pair<long, bool>>> memo;

pair<long, bool> palindromes(int i, int j) {
    if (i > j) return { 0LL, true };
    if (i == j) return { 1LL, true };

    auto &ans = memo[i][j - i - 1];
    if (~ans.fst) return ans;

    auto l = palindromes(i + 1, j);
    auto r = palindromes(i, j - 1);
    auto lr = palindromes(i + 1, j - 1);

    ans.fst = l.fst + r.fst - lr.fst;
    if (lr.snd && s[i] == s[j]) {
        ans.fst++;
        ans.snd = true;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int n = size(s);

    memo.assign(n, vector<pair<long, bool>>());
    for (int i = 0; i < n - 1; i++)
        memo[i].assign(n - i - 1, make_pair(-1, false));

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        long ans = palindromes(--l, --r).fst;
        cout << ans << "\n";
    }
}