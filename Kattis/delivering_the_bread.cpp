#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct BinaryLifting {
private:
    int n;
    vector<vector<int>> nxt;
    vector<vector<llong>> cost;

public:
    BinaryLifting(int n, vector<pair<int, int>> &f) {
        this->n = n;

        nxt.assign(LOG, vector<int>(n));
        cost.assign(LOG, vector<llong>(n));

        for (int i = 0; i < n; i++) {
            nxt[0][i] = f[i].first;
            cost[0][i] = f[i].second;
        }

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++) {
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
                cost[i][j] = cost[i - 1][j] + cost[i - 1][nxt[i - 1][j]];
            }
    }

    pair<int, llong> kth(int v, int k) {
        llong c = 0LL;
        for (int i = 0; i < LOG; i++)
            if (k & (1 << i)) {
                c += cost[i][v];
                v = nxt[i][v];
            }

        return make_pair(v, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, D, Q;
    cin >> N >> K >> D >> Q;

    vector<int> d(N);
    for (int i = 0; i < N; i++)
        cin >> d[i];

    vector<int> k(N);
    for (int i = 0; i < N; i++)
        cin >> k[i];

    vector<vector<pair<int, int>>> positions(K, vector<pair<int, int>>());
    for (int i = 0; i < N; i++)
        positions[k[i]].emplace_back(d[i], i);

    for (int i = 0; i < K; i++)
        sort(positions[i].begin(), positions[i].end());

    vector<pair<int, int>> f(N);
    for (int i = 0; i < N; i++) {
        int nxt_k = (k[i] + 1) % K;
        auto it = lower_bound(positions[nxt_k].begin(), positions[nxt_k].end(), make_pair(d[i], 0));

        if (it == positions[nxt_k].end())
            it = lower_bound(positions[nxt_k].begin(), positions[nxt_k].end(), make_pair(0, 0));

        assert(it != positions[nxt_k].end());

        int nxt_i = it->second;
        int cost = it->first >= d[i] ? it->first - d[i] : D - d[i] + it->first;

        f[i] = make_pair(nxt_i, cost);
    }

    BinaryLifting solver(N, f);
    while (Q--) {
        int dq, kq, nq;
        cin >> dq >> kq >> nq;

        auto it = lower_bound(positions[kq].begin(), positions[kq].end(), make_pair(dq, 0));
        if (it == positions[kq].end())
            it = lower_bound(positions[kq].begin(), positions[kq].end(), make_pair(0, 0));

        assert(it != positions[kq].end());

        int first_i = it->second;
        int cost = it->first >= dq ? it->first - dq : D - dq + it->first;

        llong ans = cost + solver.kth(first_i, nq - 1).second;
        cout << ans << "\n";
    }
}