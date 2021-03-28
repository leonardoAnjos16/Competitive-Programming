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

const int INF = 1e9;
const int MAX = 1e5 + 5;

int K, C[20];
vector<vi> g;
int dists[20][MAX];

void get_dists() {
    for (int i = 0; i < K; i++) {
        bitset<MAX> vis;
        for (int j = 0; j < size(g); j++)
            dists[i][j] = -1;

        queue<int> aux;
        aux.push(C[i]);

        vis[C[i]] = true;
        dists[i][C[i]] = 0;

        while (!aux.empty()) {
            int v = aux.front(); aux.pop();
            for (auto u: g[v]) {
                if (!vis[u]) {
                    aux.push(u);
                    vis[u] = true;
                    dists[i][u] = dists[i][v] + 1;
                }
            }
        }

        dists[K][C[i]] = 0;
    }
}

int memo[20][1 << 17];

int stones(int v, int used = 0) {
    if (used + 1 == (1 << K)) return 0;

    int &ans = memo[v][used];
    if (~ans) return ans;

    ans = INF;
    for (int i = 0; i < K; i++) if (!(used & (1 << i)))
        ans = min(ans, dists[v][C[i]] + stones(i, used | (1 << i)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    g.assign(N, vi());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        g[A - 1].pb(B - 1);
        g[B - 1].pb(A - 1);
    }

    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> C[i], C[i]--;

    get_dists();

    bool possible = true;
    for (int i = 0; i < K && possible; i++)
        for (int j = 0; j < K && possible; j++)
            if (dists[i][C[j]] == -1) possible = false;

    if (!possible) cout << "-1\n";
    else {
        memset(memo, -1, sizeof memo);

        int ans = stones(K) + 1;
        cout << ans << "\n";
    }
}