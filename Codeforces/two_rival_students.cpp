#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_students, num_swaps, first, second;
        scanf("%d %d %d %d", &num_students, &num_swaps, &first, &second);

        if (first > second) {
            int aux = first;
            first = second;
            second = aux;
        }

        while (num_swaps > 0 && first > 1) {
            first--;
            num_swaps--;
        }

        while (num_swaps > 0 && second < num_students) {
            second++;
            num_swaps--;
        }

        printf("%d\n", (second - first));
    }
}