#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX_S = 1e6 + 1;

int n, q;
vector<int> a, x;
vector<vector<int>> tree;
vector<int> sums;

int to_index(int i, int sum) {
    return i * MAX_S + sum;
}

bool possible(int node = 0, int parent = -1) {
    if (tree[node].empty()) return true;

    long mx = INT_MIN;
    for (auto child: tree[node])
        if (child != parent) {
            if (!possible(child, node))
                return false;
            
            mx = max(mx, 1LL * a[child]);
        }

    if (a[node] >= mx) return true;

    long diff = mx - a[node];
    auto it = lower_bound(sums.begin(), sums.end(), diff);

    if (it == sums.end())
        return false;

    a[node] += *it;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    tree.resize(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    x.resize(q);
    for (int i = 0; i < q; i++)
        cin >> x[i];

    bitset<MAX_S> memo;
    memo[0] = true;

    for (int i = 0; i < q; i++)
        memo |= memo << x[i];

    for (int i = 0; i < MAX_S; i++)
        if (memo[i])
            sums.push_back(i);

    if (!possible()) cout << "-1\n";
    else {
        long ans = 0LL;
        for (int i = 0; i < n; i++)
            ans += a[i];

        cout << ans << "\n";
    }
}