#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int pow(int a, int n, int mod) {
    if (!n) return 1;

    int ans = pow(a, n >> 1, mod);
    ans = (1LL * ans * ans) % mod;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % mod;
}

int mod_mult_inv(int a, int mod) {
    return pow(a, mod - 2, mod);
}

template<typename T>
int solve(vector<vector<T>> &A, vector<T> &ans, T mod) {
    int rows = A.size();
    int cols = A[0].size() - 1;
    
    int row = 0;
    vector<int> where(cols, -1);

    for (int col = 0; col < cols; col++) {
        int chosen = row;
        while (chosen < rows && !A[chosen][col]) chosen++;
        if (chosen >= rows) continue;

        where[col] = row;
        A[row].swap(A[chosen]);

        int inv = mod_mult_inv(A[row][col], mod);
        for (int i = 0; i < rows; i++)
            if (i != row) {
                int factor = (1LL * A[i][col] * inv) % mod;
                for (int j = col; j <= cols; j++) {
                    int aux = (1LL * A[row][j] * factor) % mod;
                    A[i][j] = (A[i][j] - aux + mod) % mod;
                }
            }

        row++;
    }

    int ind = 0;
    ans.assign(cols, 0);

    for (int i = 0; i < cols; i++) {
        if (where[i] == -1) ind++;
        else ans[i] = (1LL * A[where[i]][cols] * mod_mult_inv(A[where[i]][i], mod)) % mod;
    }

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            int aux = (1LL * ans[j] * A[i][j]) % mod;
            sum = (sum + aux) % mod;
        }

        if (sum != A[i][cols]) return 0;
    }

    return pow(mod, ind, MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<int>> g(N, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            g[u - 1][v - 1] = g[v - 1][u - 1] = 1;
        }

        vector<vector<int>> A(N, vector<int>(N + 1, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (i != j) A[i][j] = g[i][j];
                else A[i][j] = K - 1;
            }

        vector<int> colors;
        int ans = solve(A, colors, K);
        cout << "Case " << t << ": " << ans << "\n";
    }
}