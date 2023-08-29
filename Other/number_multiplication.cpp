#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 4e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    vector<llong> c(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];

    vector<int> deg(N, 0);
    vector<vector<int>> g(M, vector<int>());

    for (int i = 0; i < K; i++) {
        int m, n, d;
        cin >> m >> n >> d;

        deg[n - 1] += d;
        g[m - 1].push_back(n - 1);
    }

    llong prime = 2LL;
    vector<llong> ans(M);

    for (int i = 0; i < M; i++) {
        int n = g[i][0];
        if (deg[n] == 1) prime = c[n];
        else {
            while (c[n] % prime) prime++;
            assert(prime < MAX);
        }

        for (int n: g[i])
            while (!(c[n] % prime)) {
                deg[n]--;
                c[n] /= prime;
            }

        ans[i] = prime;
    }

    for (int i = 0; i < M; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}