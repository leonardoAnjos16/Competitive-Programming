#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;

int n, dim[MAX][3];
int memo[MAX][3][3];

bool all_shorter(int box, int i, int j) {
    for (int k = 1; k <= n; k++) {
        for (int l = 0; l < 2; l++) {
            for (int m = l + 1; m < 3; m++) {
                if (dim[k][l] > dim[box][i] && dim[k][m] > dim[box][j]) return false;
                if (dim[k][m] > dim[box][i] && dim[k][l] > dim[box][j]) return false;
            }
        }
    }

    return true;
}

int height(int box = 0, int i = 0, int j = 0) {
    if (all_shorter(box, i, j)) return 0;

    int &ans = memo[box][i][j];
    if (ans != -1) return ans;

    ans = INT_MIN;
    for (int k = 1; k <= n; k++) {
        for (int l = 0; l < 2; l++) {
            for (int m = l + 1; m < 3; m++) {
                int h = l ? dim[k][0] : (m > 1 ? dim[k][1] : dim[k][2]);
                if (dim[k][l] > dim[box][i] && dim[k][m] > dim[box][j]) ans = max(ans, h + height(k, l, m));
                if (dim[k][m] > dim[box][i] && dim[k][l] > dim[box][j]) ans = max(ans, h + height(k, m, l));
            }
        }
    }

    return ans;
}

int main() {
    int case_num = 1;
    dim[0][0] = 0;

    while (scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++)
            scanf("%d %d %d", &dim[i][0], &dim[i][1], &dim[i][2]);

        memset(memo, -1, sizeof memo);

        int ans = height();
        printf("Case %d: maximum height = %d\n", case_num++, ans);
    }
}