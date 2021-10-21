#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, C;
vector<int> E;
vector<vector<pair<int, int>>> tree;

long distance(int v = 0, int p = -1) {
    long ans = 0LL;
    for (auto [u, cost]: tree[v])
        if (u != p) {
            ans += distance(u, v);

            long trips = (E[u] + C - 1) / C;
            trips <<= 1LL;

            ans += trips * cost;
            E[v] += E[u];
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;

    E.resize(N);
    for (int i = 0; i < N; i++)
        cin >> E[i];

    tree.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int A, B, cost;
        cin >> A >> B >> cost;

        tree[A - 1].emplace_back(B - 1, cost);
        tree[B - 1].emplace_back(A - 1, cost);
    }

    long ans = distance();
    cout << ans << "\n";
}