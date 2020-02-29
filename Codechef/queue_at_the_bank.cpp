#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int N; scanf("%d", &N);

        char queue[MAX];
        scanf("%s", queue);

        char last = queue[0];
        int max_group = 1;

        int counter = 1;
        for (int i = 1; i < N; i++) {
            if (queue[i] == last) counter++;
            else counter = 1, last = queue[i];

            max_group = max(max_group, counter);
        }

        printf("%d\n", max_group);
    }
}