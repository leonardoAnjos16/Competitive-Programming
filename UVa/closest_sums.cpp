#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int main() {
    int size, case_num = 1;
    while (scanf("%d", &size), size) {
        int numbers[MAX];
        for (int i = 0; i < size; i++)
            scanf("%d", &numbers[i]);

        int num_queries;
        scanf("%d", &num_queries);

        printf("Case %d:\n", case_num++);
        while (num_queries--) {
            int sum; scanf("%d", &sum);

            int best_sum = numbers[0] + numbers[1];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int curr_sum = numbers[i] + numbers[j];
                    if (i != j && abs(sum - curr_sum) < abs(sum - best_sum))
                        best_sum = curr_sum;
                }
            }

            printf("Closest sum to %d is %d.\n", sum, best_sum);
        }
    }
}