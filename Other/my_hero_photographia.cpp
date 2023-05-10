#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, m;
vector<vector<int>> mat;

void blur() {
    vector<vector<int>> nmat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    sum += mat[(i + di + n) % n][(j + dj + m) % m];

            nmat[i][j] = sum / 9;
        }

    mat = nmat;
}

void sharpen() {
    vector<vector<int>> nmat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int mn = INT_MAX, mx = INT_MIN;
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    if (di || dj) {
                        mn = min(mn, mat[(i + di + n) % n][(j + dj + m) % m]);
                        mx = max(mx, mat[(i + di + n) % n][(j + dj + m) % m]);
                    }

            if (mat[i][j] > mx) nmat[i][j] = mat[i][j] + 100;
            else if (mat[i][j] < mn) nmat[i][j] = mat[i][j] - 100;
            else nmat[i][j] = mat[i][j];
        }

    mat = nmat;
}

void shift(int x, int y) {
    vector<vector<int>> nmat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nmat[i][j] = mat[((i + y) % n + n) % n][((j - x) % m + m) % m];

    mat = nmat;
}

void flip_horizontal() {
    for (int i = 0; i < n; i++)
        for (int lj = 0, rj = m - 1; lj < rj; lj++, rj--)
            swap(mat[i][lj], mat[i][rj]);
}

void flip_vertical() {
    for (int li = 0, ri = n - 1; li < ri; li++, ri--)
        for (int j = 0; j < m; j++)
            swap(mat[li][j], mat[ri][j]);
}

void rotate_clockwise() {
    vector<vector<int>> nmat(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nmat[j][n - i - 1] = mat[i][j];

    swap(n, m);
    mat = nmat;
}

void rotate_counter_clockwise() {
    vector<vector<int>> nmat(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nmat[m - j - 1][i] = mat[i][j];

    swap(n, m);
    mat = nmat;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    mat.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int k; cin >> k;
    while (k--) {
        string op; cin >> op;
        if (op == "Blur") blur();
        else if (op == "Sharpen") sharpen();
        else if (op == "Rotate") {
            string dir; cin >> dir;
            if (dir == "CW") rotate_clockwise();
            else rotate_counter_clockwise();
        }
        else if (op == "Flip") {
            string dir; cin >> dir;
            if (dir == "Horizontal") flip_horizontal();
            else flip_vertical();
        }
        else {
            int x, y;
            cin >> x >> y;
            shift(x, y);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            cout << mat[i][j];
        }

        cout << "\n";
    }
}