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

const int MAX = 2e3 + 5;

int p[MAX], sz[MAX];

void build() {
    for (int i = 1; i < MAX; i++)
        p[i] = i, sz[i] = 1;
}

int find(int i) {
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] > sz[j]) swap(i, j);
    if (i != j) sz[j] += sz[i];
    p[i] = j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    build();

    vector<pii> coords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        join(x, y + 1000);
        coords[i] = { x, y };
    }

    set<int> groups;
    for (int i = 0; i < n; i++)
        groups.insert(find(coords[i].fst));

    int ans = size(groups) - 1;
    cout << ans << "\n";
}