#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> tree;
vector<vector<int>> memo;

int solutions(bool know = false, int node = 0) {
    if (tree[node].empty()) return 1;

    int &ans = memo[know][node];
    if (~ans) return ans;

    int sz = tree[node].size();
    vector<int> pprod(sz + 1, 1);

    for (int i = 1; i <= sz; i++)
        pprod[i] = (1LL * pprod[i - 1] * solutions(false, tree[node][i - 1])) % MOD;

    vector<int> sprod(sz + 2, 1);
    for (int i = sz; i > 0; i--)
        sprod[i] = (1LL * sprod[i + 1] * solutions(false, tree[node][i - 1])) % MOD;

    ans = 0;
    for (int i = 1; i <= sz; i++) {
        int nprod = (1LL * pprod[i - 1] * sprod[i + 1]) % MOD;
        nprod = (1LL * nprod * solutions(true, tree[node][i - 1])) % MOD;
        ans = (ans + nprod) % MOD;
    }

    if (!know) ans = (ans + pprod[sz]) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int P; cin >> P;
        tree[P - 1].push_back(i);
    }

    memo.assign(2, vector<int>(N + 5, -1));

    int ans = solutions();
    cout << ans << "\n";
}