#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n, p;
vector<int> w;
vector<vector<pair<int, int>>> flights;
vector<vector<pair<llong, llong>>> dist;

void get_dists() {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    dist.assign(n, vector<pair<llong, llong>>(n, make_pair(INF, 0LL)));
    dist[0][0] = make_pair(0LL, p);

    using t4 = tuple<llong, llong, int, int>;
    priority_queue<t4, vector<t4>, greater<t4>> heap;
    heap.emplace(0LL, -p, 0, 0);

    while (!heap.empty()) {
        auto [days, money, city, best] = heap.top(); heap.pop();
        if (vis[city][best]) continue;
        vis[city][best] = true;

        money = -money;
        for (auto [ncity, cost]: flights[city]) {
            llong ndays = days;
            llong nmoney = money - cost;

            if (cost > money) {
                llong need = cost - money;
                llong extra = (need + w[best] - 1LL) / w[best];
                nmoney += extra * w[best];
                ndays += extra;
            }

            int nbest = w[ncity] > w[best] ? ncity : best;
            if (ndays < dist[ncity][nbest].first || (ndays == dist[ncity][nbest].first && nmoney > dist[ncity][nbest].second)) {
                dist[ncity][nbest] = make_pair(ndays, nmoney);
                heap.emplace(ndays, -nmoney, ncity, nbest);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m;
        cin >> n >> m >> p;

        w.resize(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];

        flights.assign(n, vector<pair<int, int>>());
        for (int i = 0; i < m; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            flights[a - 1].emplace_back(b - 1, s);
        }

        get_dists();

        llong ans = INF;
        for (int i = 0; i < n; i++)
            ans = min(ans, dist[n - 1][i].first);

        if (ans >= INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}