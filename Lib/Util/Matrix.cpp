struct Matrix {
    int rows, cols;
    vector<vector<long>> m;

    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        m.assign(rows, vector<long>(cols, 0LL));
    }

    Matrix(vector<vector<long>> &m) {
        this->rows = m.size();
        this->cols = m[0].size();

        this->m.assign(rows, vector<long>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->m[i][j] = m[i][j];
    }

    Matrix operator *(Matrix other) {
        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans.m[i][j] += m[i][k] * other.m[k][j];
                    ans.m[i][j] %= MOD;
                }

        return ans;
    }
};