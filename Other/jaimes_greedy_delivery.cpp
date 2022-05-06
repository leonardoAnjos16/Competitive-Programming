#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int N, K;
vector<vector<int>> g;
vector<vector<int>> dists;

int O, T;
vector<int> deliveries;
vector<pair<int, int>> special;
vector<vector<vector<int>>> memo;

void get_dists(int start) {
    dists[start].assign(N, -1);
    dists[start][start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v])
            if (dists[start][u] == -1) {
                q.push(u);
                dists[start][u] = dists[start][v] + K;
            }
    }
}

int money(bool delivered_special = false, int i = 0, int time = 0) {
    if (time > T) return -INF;

    int prev = delivered_special ? special[i - 1].first - 1 : (i ? deliveries[i - 1] - 1 : 0);
    int curr = i < O ? deliveries[i] - 1 : 0;

    int dist = dists[prev][curr];
    if (dist == -1) return -INF;

    if (i >= O) return time + dist <= T ? 0 : -INF;

    int &ans = memo[delivered_special][i][time];
    if (~ans) return ans;

    ans = money(false, i + 1, time + dist);
    if (dists[deliveries[i] - 1][special[i].first - 1] != -1)
        ans = max(ans, money(true, i + 1, time + dist + dists[deliveries[i] - 1][special[i].first - 1]) + special[i].second);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M >> K;

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    dists.resize(N);
    for (int i = 0; i < N; i++)
        get_dists(i);

    cin >> O >> T;

    deliveries.resize(O);
    for (int i = 0; i < O; i++)
        cin >> deliveries[i];

    special.resize(O);
    for (int i = 0; i < O; i++) {
        int d, v;
        cin >> d >> v;
        special[i] = make_pair(d, v);
    }

    memo.assign(2, vector<vector<int>>(O + 5, vector<int>(T + 5, -1)));

    int ans = money();
    if (ans < 0) cout << "Impossible\n";
    else cout << ans << "\n";
}