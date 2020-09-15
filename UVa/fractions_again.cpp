#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        int x[MAX], y[MAX];
        int counter = 0;

        for (int i = k + 1; i <= (k << 1); i++) {
            if ((i * k) % (i - k) == 0) {
                x[counter] = (i * k) / (i - k);
                y[counter++] = i;
            }
        }

        printf("%d\n", counter);
        for (int i = 0; i < counter; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
    }
}