#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int N;
vector<vector<vector<llong>>> dists;
vector<vector<llong>> cdists;

void get_dists(int l, int r) {
    for (int k = l; k <= r; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cdists[i][j] = min(cdists[i][j], cdists[i][k] + cdists[k][j]);
}

void solve(int l, int r) {
    if (l == r) dists[l] = cdists;
    else {
        int m = (l + r) / 2;
        vector<vector<llong>> odists = cdists;

        get_dists(m + 1, r);
        solve(l, m);

        cdists.swap(odists);
        get_dists(l, m);
        solve(m + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    vector<int> U(M), V(M);
    cdists.assign(N, vector<llong>(N, INF));

    for (int i = 0; i < M; i++) {
        int L;
        cin >> U[i] >> V[i] >> L;

        U[i]--; V[i]--;
        cdists[U[i]][V[i]] = cdists[V[i]][U[i]] = L;
    }

    for (int i = 0; i < N; i++)
        cdists[i][i] = 0LL;

    dists.resize(N);
    solve(0, N - 1);

    for (int i = 0; i < M; i++) {
        llong ans = INF;
        for (int j = 0; j < N; j++)
            if (j != U[i] && j != V[i])
                ans = min(ans, dists[V[i]][U[i]][j] + dists[U[i]][j][V[i]]);

        if (ans >= INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}