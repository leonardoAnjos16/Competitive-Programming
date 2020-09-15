#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char x[MAX]; scanf("%s", x);
        char y[MAX]; scanf("%s", y);

        int x_size = strlen(x);
        int y_size = strlen(y);

        reverse(x, x + x_size);
        reverse(y, y + y_size);

        int i = 0;
        while (y[i] == '0') i++;

        int j = i;
        while (x[j] == '0') j++;

        int ans = j - i;
        printf("%d\n", ans);
    }
}