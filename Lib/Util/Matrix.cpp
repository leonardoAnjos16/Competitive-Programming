template<typename T = long>
struct Matrix {
    int rows, cols;
    T m[MAX][MAX];

    Matrix(int rows, int cols): rows(rows), cols(cols) {
        memset(m, 0, sizeof m);
    }

    Matrix(T m[MAX][MAX], int rows, int cols): rows(rows), cols(cols) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->m[i][j] = m[i][j];
    }

    Matrix operator *(Matrix &other) {
        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans.m[i][j] += m[i][k] * other.m[k][j];
                    ans.m[i][j] %= MOD;
                }

        return ans;
    }

    T* operator [](int row) {
        return m[row];
    }
};