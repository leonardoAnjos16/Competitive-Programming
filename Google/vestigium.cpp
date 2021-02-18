#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        int rows[MAX][MAX] = {0}, cols[MAX][MAX] = {0};

        int k = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int M; cin >> M;
                if (i == j) k += M;

                rows[i][M]++;
                cols[j][M]++;
            }
        }

        int r = 0, c = 0;
        for (int i = 0; i < N; i++) {
            bool row = false, col = false;
            for (int j = 1; j <= N; j++) {
                if (rows[i][j] > 1) row = true;
                if (cols[i][j] > 1) col = true;
            }

            r += row;
            c += col;
        }

        cout << "Case #" << t << ": " << k << " " << r << " " << c << "\n";
    }
}