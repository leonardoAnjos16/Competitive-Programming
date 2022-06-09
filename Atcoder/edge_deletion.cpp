#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;

int N;
vector<vector<pair<int, int>>> g;
vector<vector<long>> dists;

void get_dists() {
    dists.assign(N, vector<long>(N, INF));
    for (int i = 0; i < N; i++) {
        dists[i][i] = 0LL;
        for (auto [v, w]: g[i])
            dists[i][v] = w;
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    g.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        g[A - 1].emplace_back(B - 1, C);
        g[B - 1].emplace_back(A - 1, C);
    }

    int ans = 0;
    get_dists();

    for (int i = 0; i < N; i++)
        for (auto [v, w]: g[i]) {
            if (w > dists[i][v]) ans++;
            else {
                bool possible = false;
                for (int j = 0; j < N && !possible; j++)
                    if (j != i && j != v && dists[i][j] + dists[j][v] == w)
                        possible = true;

                ans += possible;
            }
        }

    cout << (ans >> 1) << "\n";
}