#include <bits/stdc++.h>

using namespace std;

#define MAX 30

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int n; scanf("%d", &n);
        int pop[MAX][3];

        for (int i = 0; i < n; i++)
            scanf("%d %d %d", &pop[i][0], &pop[i][1], &pop[i][2]);

        int min_sum = INT_MAX, O[5], offices[5];
        for (O[0] = 0; O[0] < 21; O[0]++) {
            for (O[1] = O[0] + 1; O[1] < 22; O[1]++) {
                for (O[2] = O[1] + 1; O[2] < 23; O[2]++) {
                    for (O[3] = O[2] + 1; O[3] < 24; O[3]++) {
                        for (O[4] = O[3] + 1; O[4] < 25; O[4]++) {
                            int sum = 0;
                            for (int i = 0; i < n; i++) {
                                int min_dist = INT_MAX;
                                for (int j = 0; j < 5; j++) {
                                    int row = O[j] / 5, col = O[j] % 5;
                                    int dist = abs(row - pop[i][0]) + abs(col - pop[i][1]);
                                    min_dist = min(min_dist, dist);
                                }

                                sum += min_dist * pop[i][2]; 
                            }

                            if (sum < min_sum) {
                                min_sum = sum;
                                for (int i = 0; i < 5; i++)
                                    offices[i] = O[i];
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (i) printf(" ");
            printf("%d", offices[i]);
        }

        printf("\n");
    }
}