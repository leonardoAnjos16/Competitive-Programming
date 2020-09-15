#include <bits/stdc++.h>

using namespace std;

const int MAX = 9;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int sudoku[MAX][MAX];
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                scanf("%1d", &sudoku[i][j]);

        for (int i = 0; i < MAX; i++)
            if (++sudoku[i][(3 * (i % 3)) + (i / 3)] > MAX) sudoku[i][(3 * (i % 3)) + (i / 3)] = 1;

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++)
                printf("%d", sudoku[i][j]);

            printf("\n");
        }
    }
}