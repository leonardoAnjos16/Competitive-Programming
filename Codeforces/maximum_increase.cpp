#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int counter = 1, max_len = 0;

    int last; scanf("%d", &last);
    for (int i = 1; i < n; i++) {
        int a; scanf("%d", &a);

        if (a > last) counter++;
        else {
            max_len = max(max_len, counter);
            counter = 1;
        }

        last = a;
    }

    max_len = max(max_len, counter);
    printf("%d\n", max_len);
}