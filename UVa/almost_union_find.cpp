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

const int MAX = 2e5 + 5;

int n, ds[MAX], sz[MAX], sum[MAX];

void build() {
    for (int i = 0; i < n; i++)
        ds[i] = n + i;

    for (int i = n; i < 2 * n; i++)
        ds[i] = i, sz[i] = 1, sum[i] = i - n;
}

int find(int i) {
    if (ds[i] == i) return i;
    return ds[i] = find(ds[i]);
}

void move(int i, int j) {
    sz[find(i)]--;
    sum[find(i)] -= i;

    j = find(j);
    ds[i] = j;

    sz[j]++;
    sum[j] += i;
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] < sz[j]) swap(i, j);
    if (i != j) sz[i] += sz[j], sum[i] += sum[j];
    ds[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    while (cin >> n >> m) {
        build();
        while (m--) {
            int op, p;
            cin >> op >> p;

            if (op == 1) {
                int q; cin >> q;
                join(--p, --q);
            } else if (op == 2) {
                int q; cin >> q;
                move(--p, --q);
            } else {
                p = find(--p);
                cout << sz[p] << " " << (sum[p] + sz[p]) << "\n";
            }
        }
    }
}