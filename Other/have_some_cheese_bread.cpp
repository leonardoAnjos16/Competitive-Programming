#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

int N;
vector<bool> house;
vector<vector<int>> g;
vector<bool> has_ans;
vector<pair<int, int>> memo;

pair<int, int> min_max(int v = 0) {
    if (v == N - 1) return make_pair(house[v], house[v]);

    pair<int, int> &ans = memo[v];
    if (has_ans[v]) return ans;

    ans.first = INF;
    ans.second = -INF;

    for (int u: g[v]) {
        pair<int, int> aux = min_max(u);
        if (aux.first < ans.first) ans.first = aux.first;
        if (aux.second > ans.second) ans.second = aux.second;
    }

    has_ans[v] = true;
    ans.first += house[v];
    ans.second += house[v];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, M;
    cin >> N >> C >> M;

    house.assign(N, false);
    while (C--) {
        int h; cin >> h;
        house[h - 1] = true;
    }

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        g[v - 1].push_back(w - 1);
    }

    has_ans.assign(N + 5, false);
    memo.assign(N + 5, make_pair(-1, -1));

    auto [mn, mx] = min_max();
    cout << mn << " " << mx << "\n";
}