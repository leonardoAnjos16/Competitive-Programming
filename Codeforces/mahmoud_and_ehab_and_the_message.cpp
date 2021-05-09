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

int a[MAX], p[MAX], sz[MAX], min_cost[MAX];

void build(int n) {
    for (int i = 0; i < n; i++)
        p[i] = i, sz[i] = 1, min_cost[i] = a[i];
}

int find(int i) {
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] > sz[j]) swap(i, j);

    p[i] = j;
    if (i != j)
        sz[j] += sz[i], min_cost[j] = min(min_cost[j], min_cost[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;

    map<string, int> indices;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        indices[s] = i;
    }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(n);
    while (k--) {
        int x, u;
        cin >> x >> u;

        for (int i = 1; i < x; i++) {
            int v; cin >> v;
            join(u - 1, v - 1);
        }
    }

    long ans = 0LL;
    while (m--) {
        string s; cin >> s;
        int u = find(indices[s]);
        ans += min_cost[u];
    }

    cout << ans << "\n";
}