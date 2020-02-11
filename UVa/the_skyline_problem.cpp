#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int main() {
    int L, H, R, min = INT_MAX, max = INT_MIN, heights[MAX] = {0};
    while (scanf("%d %d %d", &L, &H, &R) != EOF) {
        for (int i = L; i < R; i++)
            if (H > heights[i])
                heights[i] = H;

        if (L < min) min = L;
        if (R > max) max = R;
    }

    printf("%d %d", min, heights[min]);

    int last_height = heights[min];
    for (int i = min; i <= max; i++) {
        if (heights[i] != last_height) {
            printf(" %d %d", i, heights[i]);
            last_height = heights[i];
        }
    }

    printf("\n");
}