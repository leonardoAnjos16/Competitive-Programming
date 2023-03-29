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

    int freedom = 0;
    ans.assign(cols, 0);

    for (int i = 0; i < cols; i++) {
        if (where[i] == -1) freedom++;
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

    return pow(mod, freedom, MOD);
}

int solve(vector<vector<ldouble>> &A, vector<ldouble> &ans) {
    int rows = A.size();
    int cols = A[0].size() - 1;

    int row = 0;
    vector<int> where(cols, -1);

    for (int col = 0; col < cols; col++) {
        int chosen = row;
        // Maybe use heuristic of row with greatest absolute value for coefficient at col
        while (chosen < rows && !sign(A[chosen][col])) chosen++;
        if (chosen >= rows) continue;

        where[col] = row;
        A[row].swap(A[chosen]);

        for (int i = 0; i < rows; i++)
            if (i != row) {
                ldouble factor = A[i][col] / A[row][col];
                for (int j = col; j <= cols; j++)
                    A[i][j] -= A[row][j] * factor;
            }

        row++;
    }

    bool freedom = false;
    ans.assign(cols, 0.0L);

    for (int i = 0; i < cols; i++) {
        if (where[i] == -1) freedom = true;
        else ans[i] = A[where[i]][cols] / A[where[i]][i];
    }

    for (int i = 0; i < rows; i++) {
        ldouble sum = 0.0L;
        for (int j = 0; j < cols; j++)
            sum += ans[j] * A[i][j];

        if (sign(sum - A[i][cols]))
            return 0;
    }

    return freedom ? INF : 1;
}
