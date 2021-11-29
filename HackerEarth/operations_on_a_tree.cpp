#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, K;
vector<int> A;
vector<vector<int>> tree;
vector<pair<long, long>> sums;

void get_sums(int i = 0, int p = -1) {
    sums[i] = make_pair(A[i], A[i] ^ K);
    for (auto v: tree[i])
        if (v != p) {
            get_sums(v, i);
            sums[i].first += sums[v].first;
            sums[i].second += sums[v].second;
        }
}

long best_sum(int i = 0, int p = -1) {
    long ans = sums[0].first - sums[i].first + sums[i].second;
    long aux = sums[0].second - sums[i].second;

    for (auto v: tree[i])
        if (v != p) {
            ans = max(ans, aux + sums[i].second - sums[v].second + sums[v].first);
            ans = max(ans, best_sum(v, i));
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N >> K;

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

        sums.resize(N);
        get_sums();

        long ans = max(sums[0].first, best_sum());
        cout << ans << "\n";
    }
}