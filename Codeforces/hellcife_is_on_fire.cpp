#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 1e5 + 5;
const long INF = 1e18;

int N, T[MAX];
vector<int> starts;
vector<vector<pii>> g;
vector<long> dists;

void djikstra() {
    bitset<MAX> vis;
    dists.assign(N, INF);

    pq<pll, vector<pll>, greater<pll>> heap;
    for (auto v: starts) {
        dists[v] = 0LL;
        heap.emplace(0LL, v);
    }

    for (int i = 0; i < N; i++) {
        int v;
        do {
            if (heap.empty()) return;
            v = heap.top().snd; heap.pop();
        } while (vis[v]);

        vis[v] = true;
        for (auto p: g[v]) {
            int u = p.fst, w = p.snd;
            if (!vis[u] && dists[v] + T[v] + w < dists[u]) {
                dists[u] = dists[v] + T[v] + w;
                heap.emplace(dists[u], u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    g.assign(N, vector<pii>());
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        g[A - 1].pb({ B - 1, C });
        g[B - 1].pb({ A - 1, C });
    }

    for (int i = 0; i < N; i++)
        cin >> T[i];

    starts.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> starts[i];
        starts[i]--;
    }

    djikstra();
    for (int i = 0; i < N; i++)
        cout << (dists[i] + T[i]) << "\n";
}