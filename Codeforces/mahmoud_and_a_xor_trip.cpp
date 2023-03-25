#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 25;

vector<int> a;
vector<vector<int>> tree;
vector<vector<int>> cnt;
vector<int> sz;

llong sum(int node = 0, int parent = -1) {
    sz[node] = 1;
    llong ans = a[node];

    for (int child: tree[node])
        if (child != parent) {
            ans += sum(child, node);
            sz[node] += sz[child];
        }

    cnt[node].assign(LOG, 0LL);
    for (int i = 0; i < LOG; i++)
        if (a[node] & (1 << i))
            cnt[node][i] = 1LL;

    int size = 1;
    for (int child: tree[node])
        if (child != parent) {
            for (int i = 0; i < LOG; i++) {
                llong paths = 1LL * (size - cnt[node][i]) * cnt[child][i] + 1LL * cnt[node][i] * (sz[child] - cnt[child][i]);
                ans += paths * (1 << i);

                if (a[node] & (1 << i)) cnt[node][i] += sz[child] - cnt[child][i];
                else cnt[node][i] += cnt[child][i];
            }

            size += sz[child];
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    cnt.resize(n);
    sz.resize(n);

    llong ans = sum();
    cout << ans << "\n";
}