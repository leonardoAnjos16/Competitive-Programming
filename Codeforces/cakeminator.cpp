#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int main() {
    int r, c; scanf("%d %d", &r, &c);

    char cake[MAX][MAX];
    bitset<MAX> rows, cols;

    for (int i = 0; i < r; i++) {
        scanf("%s", cake[i]);
        for (int j = 0; j < c; j++)
            if (cake[i][j] == 'S')
                rows[i] = cols[j] =  true;
    }

    int num_rows = 0;
    for (int i = 0; i < r; i++)
        if (!rows[i]) num_rows++;

    int num_cols = 0;
    for (int i = 0; i < c; i++)
        if (!cols[i]) num_cols++;

    int ans = num_rows * c + num_cols * (r - num_rows);
    printf("%d\n", ans);
}