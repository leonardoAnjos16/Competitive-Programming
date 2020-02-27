#include <bits/stdc++.h>

using namespace std;

#define MAX 200005

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int n, m; scanf("%d %d", &n, &m);

        char combo[MAX];
        scanf("%s", combo);

        int tries[MAX];
        for (int i = 0; i < m; i++)
            scanf("%d", &tries[i]);

        sort(tries, tries + m);

        int pressed[26] = {0};
        for (int i = 0; i < n; i++)
            pressed[combo[i] - 'a']++;

        for (int i = 0; i < n; i++) {
            int counter = tries + m - lower_bound(tries, tries + m, i + 1);
            pressed[combo[i] - 'a'] += counter;
        }

        for (int i = 0; i < 26; i++)
            printf("%d ", pressed[i]);

        printf("\n");
    }
}