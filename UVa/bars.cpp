#include <bits/stdc++.h>

using namespace std;

#define MAX 25

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int length, num_bars;
        scanf("%d\n%d", &length, &num_bars);
        
        int bars[MAX];
        for (int i = 0; i < num_bars; i++)
            scanf("%d", &bars[i]);

        bool found = false;
        for (int i = 0; i < (1 << num_bars) && !found; i++) {
            int sum = 0;
            for (int j = 0; j < num_bars; j++)
                if (i & (1 << j))
                    sum += bars[j];

            if (sum == length) found = true;
        }

        printf("%s\n", found ? "YES" : "NO");
    }
}