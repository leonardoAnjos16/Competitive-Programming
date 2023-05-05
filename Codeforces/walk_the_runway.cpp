#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 5e3 + 5;

vector<int> p;
vector<vector<int>> g;
vector<llong> memo;

llong profit(int v) {
    llong &ans = memo[v];
    if (~ans) return ans;

    ans = 0LL;
    for (int u: g[v])
        ans = max(ans, profit(u));

    ans += p[v];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    p.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<vector<int>> r(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> r[i][j];

    vector<bitset<MAX>> before(n);
    for (int i = 0; i < n; i++)
        before[i].set();

    for (int i = 0; i < m; i++) {
        priority_queue<pair<int, int>> heap;
        for (int j = 0; j < n; j++)
            heap.emplace(r[i][j], j);

        vector<int> indices(n);
        for (int j = 0; j < n; j++) {
            indices[n - j - 1] = heap.top().second;
            heap.pop();
        }

        int idx = 0;
        bitset<MAX> curr;

        while (idx < n) {
            int limit = idx;
            while (limit < n && r[i][indices[limit]] == r[i][indices[idx]])
                before[indices[limit++]] &= curr;

            for (int j = idx; j < limit; j++)
                curr[indices[j]] = 1;

            idx = limit;
        }

        for (int j = 0; j < n; j++) {
            before[indices[j]] &= curr;
            curr[indices[j]] = 1;
        }
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (before[i][j])
                g[j].push_back(i);

    memo.assign(n + 5, -1LL);

    llong ans = LLONG_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, profit(i));

    cout << ans << "\n";
}