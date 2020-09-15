#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int main() {
    int f, r;
    while (scanf("%d", &f), f) {
        scanf("%d", &r);

        double front[MAX], rear[MAX];
        for (int i = 0; i < f; i++)
            scanf("%lf", &front[i]);

        for (int i = 0; i < r; i++)
            scanf("%lf", &rear[i]);

        double ratios[MAX];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < f; j++)
                ratios[(i * f) + j] = rear[i] / front[j];

        int size = f * r;
        sort(ratios, ratios + size);

        double max_spread = DBL_MIN;
        for (int i = 0; i < size - 1; i++) {
            double spread = ratios[i + 1] / ratios[i];
            max_spread = max(max_spread, spread);
        }

        printf("%.2lf\n", max_spread);
    }
}