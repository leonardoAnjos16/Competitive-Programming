#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 1; i <= num_cases; i++) {
        int num_walls;
        scanf("%d", &num_walls);

        int walls[50];
        for (int j = 0; j < num_walls; j++)
            scanf("%d", &walls[j]);

        int high_jumps = 0, low_jumps = 0;
        for (int j = 1; j < num_walls; j++) {
            if (walls[j] > walls[j - 1]) high_jumps++;
            else if (walls[j] < walls[j -1]) low_jumps++;
        }

        printf("Case %d: %d %d\n", i, high_jumps, low_jumps);
    }
}