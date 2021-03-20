#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const long INF = 1e18;
const int MAX = 1e5 + 5;

vector<pii> V, x, y;
long dis[MAX];

long dist(pii a, pii b) {
    return min(abs(a.fst - b.fst), abs(a.snd - b.snd));
}

void get_dis() {
    bitset<MAX> vis;
    for (int i = 0; i < size(V); i++)
        dis[i] = INF;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0);

    dis[0] = 0;
    for (int i = 0; i < size(V); i++) {
        int v;
        do {
            if (pq.empty()) return;
            v = pq.top().snd; pq.pop();
        } while (vis[v]);

        vis[v] = true;

        auto it = ub(all(x), make_pair(V[v].fst, v));
        if (it != x.end() && !vis[it->snd] && dis[v] + dist(V[v], V[it->snd]) < dis[it->snd]) {
            dis[it->snd] = dis[v] + dist(V[v], V[it->snd]);
            pq.emplace(dis[it->snd], it->snd);
        }

        it = lb(all(x), make_pair(V[v].fst, v));
        if (it != x.begin() && !vis[(--it)->snd] && dis[v] + dist(V[v], V[it->snd]) < dis[it->snd]) {
            dis[it->snd] = dis[v] + dist(V[v], V[it->snd]);
            pq.emplace(dis[it->snd], it->snd);
        }

        it = ub(all(y), make_pair(V[v].snd, v));
        if (it != y.end() && !vis[it->snd] && dis[v] + dist(V[v], V[it->snd]) < dis[it->snd]) {
            dis[it->snd] = dis[v] + dist(V[v], V[it->snd]);
            pq.emplace(dis[it->snd], it->snd);
        }

        it = lb(all(y), make_pair(V[v].snd, v));
        if (it != y.begin() && !vis[(--it)->snd] && dis[v] + dist(V[v], V[it->snd]) < dis[it->snd]) {
            dis[it->snd] = dis[v] + dist(V[v], V[it->snd]);
            pq.emplace(dis[it->snd], it->snd);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;

    V.pb({ sx, sy });
    for (int i = 0; i < m; i++) {
        int xi, yi;
        cin >> xi >> yi;

        V.pb({ xi, yi });
        x.pb({ xi, i + 1 });
        y.pb({ yi, i + 1 });
    }

    sort(all(x));
    sort(all(y));
    get_dis();

    long ans = abs(fx - sx) + abs(fy - sy);
    for (int i = 1; i <= m; i++)
        ans = min(ans, dis[i] + abs(fx - V[i].fst) + abs(fy - V[i].snd));

    cout << ans << "\n";
}