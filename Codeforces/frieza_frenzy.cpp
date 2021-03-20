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

int n, ds[MAX], sz[MAX];

void build() {
    for (int i = 0; i < n; i++)
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = { --u, --v };
    }

    vi order(m);
    for (int i = 0; i < m; i++)
        cin >> order[i];

    build();
    reverse(all(order));

    vi ans(m);
    int sets = n;

    for (int i = 0; i < m; i++) {
        ans[i] = sets;
        pii edge = edges[--order[i]];

        if (find(edge.fst) != find(edge.snd)) {
            sets--;
            join(edge.fst, edge.snd);
        }
    }

    reverse(all(ans));
    for (int i: ans)
        cout << i << "\n";
}