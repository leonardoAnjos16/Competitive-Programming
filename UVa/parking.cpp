#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_stores;
        scanf("%d", &num_stores);

        int min = INT_MAX, max = INT_MIN, store;
        while (num_stores--) {
            scanf("%d", &store);
            if (store < min) min = store;
            if (store > max) max = store;
        }

        int min_distance = 2 * (max - min);
        printf("%d\n", min_distance);
    }
}