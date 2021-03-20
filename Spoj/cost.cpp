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
const int MOD = 1e9;

int N, ds[MAX], sz[MAX];

void build() {
    for (int i = 0; i < N; i++)
        ds[i] = i, sz[i] = 1;
}

int find(int i) {
    if (ds[i] == i) return i;
    return ds[i] = find(ds[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] < sz[j]) swap(i, j);
    if (i != j) sz[i] += sz[j];
    ds[j] = i;
}

long mult(long a, long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    long sum = 0LL;
    pair<int, pii> edges[MAX];

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { w, { --u, --v }};
        sum += w;
    }

    build();
    sort(edges, edges + M, greater<pair<int, pii>>());

    long ans = 0;
    for (int i = 0; i < M; i++) {
        int u = edges[i].snd.fst;
        int v = edges[i].snd.snd;

        u = find(u); v = find(v);
        if (u != v) {
            long x = mult(sz[u], sum);
            x = mult(x, sz[v]);
            ans = (ans + x) % MOD;
            join(u, v);
        }

        sum -= edges[i].fst;
    }

    cout << ans << "\n";
}