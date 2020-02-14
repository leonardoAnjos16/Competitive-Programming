#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int size; scanf("%d", &size);

        int sales[MAX];
        for (int i = 0; i < size; i++)
            scanf("%d", &sales[i]);

        int sum = 0;
        for (int i = 1; i < size; i++)
            for (int j = 0; j < i; j++)
                if (sales[j] <= sales[i])
                    sum++;

        printf("%d\n", sum);
    }
}