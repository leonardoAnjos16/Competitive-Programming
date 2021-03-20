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

int n, ds[MAX], sz[MAX];

void build() {
    for (int i = 0; i < n; i++)
        ds[i] = i, sz[i] = 1;
}

int find(int i) {
    if (ds[i] == i) return i;
    return ds[i] = find(ds[i]);
}

void unite(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] < sz[j]) swap(i, j);
    if (i != j) sz[i] += sz[j];
    ds[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string S; cin >> S;
        n = size(S);

        build();
        for (int i = 1; i < n; i++)
            if (S[i] == S[i - 1]) unite(i - 1, i);

        cout << "Case " << t << ":\n";

        int q; cin >> q;
        set<int> changed;

        while (q--) {
            int op, idx;
            cin >> op >> idx;

            if (op == 2) changed.insert(idx);
            else {
                int start = find(idx);
                int end = start + sz[start] - 1;

                auto it = changed.ub(idx);
                if (it != changed.end() && *it <= end) end = *it - 1;
                if (it != changed.begin() && *(--it) >= start) start = *it + 1;

                int ans = end - start + 1;
                cout << ans << "\n";
            }
        }
    }
}