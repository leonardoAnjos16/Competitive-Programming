#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    char s[10];
    int x = 0;

    while (n--) {
        scanf("%s", s);
        if (s[1] == '+') x++;
        else x--;
    }

    printf("%d\n", x);
}