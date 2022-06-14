#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> A, gcds;
vector<vector<int>> tree;

void get_gcds(int node = 0, int parent = -1) {
    gcds[node] = A[node];
    for (int child: tree[node])
        if (child != parent) {
            get_gcds(child, node);
            gcds[node] = gcd(gcds[node], gcds[child]);
        }
}

long solve(int node = 0, int parent = -1, long sum = 0LL) {
    long curr = 0LL;
    for (int child: tree[node])
        if (child != parent)
            curr += gcds[child];

    long ans = sum + curr;
    for (int child: tree[node])
        if (child != parent)
            ans = max(ans, solve(child, node, sum + curr - gcds[child]));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        gcds.resize(N);
        get_gcds();

        long ans = solve();
        cout << ans << "\n";
    }
}