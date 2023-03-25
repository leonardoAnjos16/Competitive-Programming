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
