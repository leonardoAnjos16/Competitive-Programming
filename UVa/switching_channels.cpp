#include <bits/stdc++.h>

using namespace std;

#define MAX 10

int main() {
    int num_progs, case_num = 1;
    while (scanf("%d", &num_progs), num_progs) {
        int progs[MAX];
        for (int i = 0; i < num_progs; i++)
            scanf("%d", &progs[i]);

        int num_points;
        scanf("%d", &num_points);

        int points[MAX][2];
        for (int i = 0; i < num_points; i++)
            scanf("%d %d", &points[i][0], &points[i][1]);

        int errors[5], sol[MAX];
        for (int i = 0; i < 5; i++)
            errors[i] = INT_MAX;

        sort(progs, progs + num_progs);
        do {
            int prefix_sum[MAX] = {0}, curr_error[MAX] = {0};

            prefix_sum[0] = 0;
            for (int i = 1; i <= num_progs; i++)
                prefix_sum[i] = prefix_sum[i - 1] + progs[i - 1];

            for (int i = 0; i < num_points; i++) {
                int lb = lower_bound(prefix_sum, prefix_sum + num_progs + 1, points[i][1]) - prefix_sum;
                int ub = upper_bound(prefix_sum, prefix_sum + num_progs + 1, points[i][1]) - prefix_sum;

                if (lb > num_progs || prefix_sum[lb] > points[i][1]) lb--;
                if (ub > num_progs) ub--;

                curr_error[points[i][0] - 1] += min(abs(points[i][1] - prefix_sum[lb]), abs(points[i][1] - prefix_sum[ub]));
            }

            int pos = -1;
            while (++pos < 5 && curr_error[pos] == errors[pos]);

            if (pos < 5 && curr_error[pos] < errors[pos]) {
                for (int i = pos; i < 5; i++)
                    errors[i] = curr_error[i];

                for (int i = 0; i < num_progs; i++)
                    sol[i] = progs[i];
            }
        } while (next_permutation(progs, progs + num_progs));

        printf("Data set %d\n", case_num++);
        printf("Order:");

        for (int i = 0; i < num_progs; i++)
            printf(" %d", sol[i]);

        int total_error = 0;
        for (int i = 0; i < 5; i++)
            total_error += errors[i];

        printf("\nError: %d\n", total_error);
    }
}