#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int main() {
    int num_cells, num_platforms, jump_distance;
    scanf("%d %d %d", &num_cells, &num_platforms, &jump_distance);

    int platforms[MAX], river[MAX], sum = 0;
    for (int i = 0; i < num_platforms; i++) {
        scanf("%d", &platforms[i]);
        sum += platforms[i];
    }

    for (int i = 0; i < num_cells; i++)
        river[i] = 0;

    int initial_pos = 0, curr_platform = 0, remaining_cells = num_cells;
    while (curr_platform < num_platforms) {
        int zero_cells = (num_cells - initial_pos) - sum;
        int platforms_distance = zero_cells / ((num_platforms - curr_platform) + 1);
        int max_distance = min(jump_distance, platforms_distance);

        initial_pos += max_distance;
        for (int i = 0; i < platforms[curr_platform]; i++)
            river[initial_pos + i] = (curr_platform + 1);

        initial_pos += platforms[curr_platform];
        sum -= platforms[curr_platform++];
    }

    if (num_cells - initial_pos >= jump_distance) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < num_cells; i++)
            printf("%d ", river[i]);

        printf("\n");
    }
}