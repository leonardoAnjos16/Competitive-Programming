#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_piles, num_days;
        scanf("%d %d", &num_piles, &num_days);

        int piles[MAX];
        for (int i = 0; i < num_piles; i++)
            scanf("%d", &piles[i]);

        while (num_days--) {
            if (piles[1]) piles[0]++, piles[1]--;
            else {
                int pos = 1;
                while (++pos < num_piles && !piles[pos]);

                if (pos < num_piles) piles[pos - 1]++, piles[pos]--;
                else break;
            }
        }

        printf("%d\n", piles[0]);
    }
}