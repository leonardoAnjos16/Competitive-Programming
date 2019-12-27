#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        char results[80];
        scanf("%s", results);

        int scores[80];
        int size = strlen(results);
        scores[0] = results[0] == 'O' ? 1 : 0;
        int sum = scores[0];

        for (int j = 1; j < size; j++) {
            if (results[j] == 'X') scores[j] = 0;
            else scores[j] = scores[j - 1] + 1;

            sum += scores[j];
        }

        printf("%d\n", sum);
    }
}