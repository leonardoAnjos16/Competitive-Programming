#include <bits/stdc++.h>

using namespace std;

int main() {
    int bottles[3][3];
    while (scanf("%d %d %d", &bottles[0][0], &bottles[0][1], &bottles[0][2]) != EOF) {
        for (int i = 1; i < 3; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &bottles[i][j]);

        char config[] = "BCG";
        int min_movements = INT_MAX;
        char best_config[4];

        do {
            int num_movements = 0;
            for (int i = 0; i < 3; i++) {
                if (config[i] == 'B') 
                    num_movements += bottles[(i + 1) % 3][0] + bottles[(i + 2) % 3][0];
                else if (config[i] == 'G')
                    num_movements += bottles[(i + 1) % 3][1] + bottles[(i + 2) % 3][1];
                else
                    num_movements += bottles[(i + 1) % 3][2] + bottles[(i + 2) % 3][2];
            }

            if (num_movements < min_movements) {
                min_movements = num_movements;
                strcpy(best_config, config);
            }
        } while (next_permutation(config, config + 3));

        printf("%s %d\n", best_config, min_movements);
    }
}