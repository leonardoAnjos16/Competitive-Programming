#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int Y;
    while (scanf("%d", &Y) != EOF) {
        int P; scanf("%d", &P);

        int years[MAX];
        for (int i = 0; i < P; i++)
            scanf("%d", &years[i]);

        int max_seq = INT_MIN, first, last;
        for (int i = 0; i < P; i++) {
            int last_index = upper_bound(years + i, years + P, years[i] + Y - 1) - years;
            int num_popes = last_index - i;

            if (num_popes > max_seq) {
                max_seq = num_popes;
                first = years[i];
                last = years[last_index - 1];
            }
        }

        printf("%d %d %d\n", max_seq, first, last);
    }
}