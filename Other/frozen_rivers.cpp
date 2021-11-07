#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<pair<int, int>>> tree;
vector<long> arrive_time;

void get_time(int v = 0, int p = -1) {
    if (~p && (int) tree[v].size() <= 1) return;

    int mn_u = -1, mn_w = INT_MAX;
    for (auto [u, w]: tree[v])
        if (u != p && w < mn_w)
            mn_u = u, mn_w = w;

    arrive_time[mn_u] = arrive_time[v] + mn_w;
    get_time(mn_u, v);

    for (auto [u, w]: tree[v])
        if (u != p && u != mn_u) {
            arrive_time[u] = arrive_time[v] + mn_w + 2 * (w - mn_w);
            get_time(u, v);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        tree.assign(N, vector<pair<int, int>>());
        for (int i = 1; i < N; i++) {
            int P, C;
            cin >> P >> C;

            tree[P - 1].emplace_back(i, C);
            tree[i].emplace_back(P - 1, C);
        }

        arrive_time.assign(N, 0LL);
        get_time();

        vector<long> leaves;
        for (int i = 1; i < N; i++)
            if ((int) tree[i].size() <= 1)
                leaves.push_back(arrive_time[i]);

        sort(leaves.begin(), leaves.end());

        int Q; cin >> Q;
        while (Q--) {
            long query_time; cin >> query_time;

            int ans = upper_bound(leaves.begin(), leaves.end(), query_time) - leaves.begin();
            cout << ans << "\n";
        }
    }
}