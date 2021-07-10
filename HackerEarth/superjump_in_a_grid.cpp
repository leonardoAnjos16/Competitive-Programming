#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int N, M;
vector<vector<int>> nr, nd, memo;

int ways(int i = 0, int j = 0) {
    if (i < 0 || j < 0) return 0;
    if (i + 1 >= N && j + 1 >= M) return 1;

    int &ans = memo[i][j];
    if (~ans) return ans;

    return ans = (ways(i, nr[i][j]) + ways(nd[i][j], j)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<string> g(N);

    for (int i = 0; i < N; i++)
        cin >> g[i];

    nr.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        int last = 0;
        while (last < M && g[i][last] == '1') last++;

        if (!i || last < M)
            for (int j = last + 1; j < M; j++)
                if (g[i][j] == '0') nr[i][last] = j, last = j;
    }

    nd.assign(N, vector<int>(M, -1));
    for (int i = 0; i < M; i++) {
        int last = 0;
        while (last < N && g[last][i] == '1') last++;

        if (!i || last < N)
            for (int j = last + 1; j < N; j++)
                if (g[j][i] == '0') nd[last][i] = j, last = j;
    }

    memo.assign(N, vector<int>(M, -1));

    int ans = ways();
    cout << ans << "\n";
}