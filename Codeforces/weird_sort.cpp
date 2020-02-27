#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int n, m; scanf("%d %d", &n, &m);

        int numbers[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &numbers[i]);

        bool positions[MAX];
        for (int i = 0; i < n; i++)
            positions[i] = false;

        int pos;
        for (int i = 0; i < m; i++) {
            scanf("%d", &pos);
            positions[pos - 1] = true;
        }

        bool sorted, swapped;
        do {
            sorted = true;
            swapped = false;

            for (int i = 0; i < n - 1; i++) {
                if (numbers[i] > numbers[i + 1]) {
                    sorted = false;

                    if (positions[i]) {
                        int aux = numbers[i];
                        numbers[i] = numbers[i + 1];
                        numbers[i + 1] = aux;

                        swapped = true;
                    }
                }
            }
        } while (!sorted && swapped);

        printf("%s\n", sorted ? "YES" : "NO");
    }
}