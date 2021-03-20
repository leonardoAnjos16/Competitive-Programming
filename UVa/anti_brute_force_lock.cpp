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

const int MAX = 505;

int N, A[MAX], ds[MAX], sz[MAX];

int dist(int a, int b) {
    int ans = 0;
    while (a || b) {
        int da = a % 10;
        int db = b % 10;

        if (da < db) swap(da, db);
        ans += min(da - db, 9 - da + db + 1);

        a /= 10; b /= 10;
    }

    return ans;
}

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

int kruskal() {
    vector<pair<int, pii>> edges;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                edges.pb({ dist(A[i], A[j]), { i, j } });

    sort(all(edges));

    int sets = N, idx = 0, ans = 0;
    while (sets > 1) {
        auto edge = edges[idx++];
        if (find(edge.snd.fst) != find(edge.snd.snd)) {
            ans += edge.fst; sets--;
            join(edge.snd.fst, edge.snd.snd);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> A[i];

        build();

        int ans = kruskal(), mn = INT_MAX;
        for (int i = 0; i < N; i++)
            mn = min(mn, dist(0, A[i]));

        ans += mn;
        cout << ans << "\n";
    }
}