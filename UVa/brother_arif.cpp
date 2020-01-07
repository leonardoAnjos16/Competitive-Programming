#include<bits/stdc++.h>

using namespace std;

#define MAX 10000

int main() {
    int R, C, N, case_num = 1;
    while (scanf("%d %d %d", &R, &C, &N), R || C || N) {
        bitset<MAX> forbidden[2];
        for (int i = 0; i < N; i++) {
            int row, column;
            scanf("%d %d", &row, &column);

            forbidden[0].set(row);
            forbidden[1].set(column);
        }

        int row, column;
        scanf("%d %d", &row, &column);

        bool can_scape = !forbidden[0].test(row) && !forbidden[1].test(column);
        if (row > 0) can_scape |= !forbidden[0].test(row - 1) && !forbidden[1].test(column);
        if (row < R - 1) can_scape |= !forbidden[0].test(row + 1) && !forbidden[1].test(column);
        if (column > 0) can_scape |= !forbidden[0].test(row) && !forbidden[1].test(column - 1);
        if (column < C - 1) can_scape |= !forbidden[0].test(row) && !forbidden[1].test(column + 1);

        printf("Case %d: ", case_num++);
        if (can_scape) printf("Escaped again! More 2D grid problems!\n");
        else printf("Party time! Let's find a restaurant!\n");
    }
}