#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

vector<vector<int>> g;
vector<int> memo;

int mex(vector<int> &nimbers) {
    sort(nimbers.begin(), nimbers.end());
    if (nimbers.empty() || nimbers[0]) return 0;

    for (int i = 1; i < (int) nimbers.size(); i++)
        if (nimbers[i] > nimbers[i - 1] + 1)
            return nimbers[i - 1] + 1;

    return nimbers.back() + 1;
}

int grundy(int v) {
    int &ans = memo[v];
    if (~ans) return ans;

    vector<int> nimbers;
    for (int u: g[v])
        nimbers.push_back(grundy(u));

    return ans = mex(nimbers);
}

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int mod) {
    return pow(a, mod - 2);
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

    return pow(mod, ind);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    memo.assign(n + 5, -1);

    int mx = 0;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cnt[grundy(i)]++;
        mx = max(mx, grundy(i));
    }

    mx <<= 1;
    if (!mx) cout << "0\n";
    else {
        int inv = mod_mult_inv(n + 1, MOD);
        vector<vector<int>> A(mx, vector<int>(mx + 1));

        for (int i = 0; i < mx; i++) {
            for (int j = 0; j < mx; j++)
                A[i][j] = (1LL * cnt[i ^ j] * inv) % MOD;

            A[i][i] = (A[i][i] - 1 + MOD) % MOD;
            A[i][mx] = i ? (-inv + MOD) % MOD : 0;
        }

        vector<int> p;
        assert(solve(A, p, MOD) == 1);
        cout << p[0] << "\n";
    }
}