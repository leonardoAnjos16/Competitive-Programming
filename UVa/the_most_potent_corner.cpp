#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 15

int get_potency(int weights[], int num_dimensions, int corner) {
    int sum = 0;
    for (int i = 0; i < num_dimensions; i++)
        sum += weights[corner ^ (1 << i)];

    return sum;
}

int get_best_neighbour_potency(int potencies[], int num_dimensions, int corner) {
    int max = INT_MIN;
    for (int i = 0; i < num_dimensions; i++) {
        int neighbour_pos = corner ^ (1 << i);
        if (potencies[neighbour_pos] > max) max = potencies[neighbour_pos];
    }

    return max;
}

int main() {
    int num_dimensions;
    while (scanf("%d", &num_dimensions) != EOF) {
        int weights[MAX], num_corners = 1 << num_dimensions;
        for (int i = 0; i < num_corners; i++)
            scanf("%d", &weights[i]);

        int potencies[MAX];
        for (int i = 0; i < num_corners; i++)
            potencies[i] = get_potency(weights, num_dimensions, i);

        int max = INT_MIN;
        for (int i = 0; i < num_corners; i++) {
            int sum = potencies[i] + get_best_neighbour_potency(potencies, num_dimensions, i);
            if (sum > max) max = sum;
        }

        printf("%d\n", max);
    }
}