#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);

    int technique[MAX];
    for (int i = 0; i < n; i++) {
        int h; scanf("%d", &h);

        h = h % (a + b);
        if (!h) h = a + b;

        technique[i] = ((h + a - 1) / a) - 1;
    }

    sort(technique, technique + n);

    int max_points = 0, counter = 0;
    while (counter < n && k >= technique[counter]) {
        max_points++;
        k -= technique[counter++];
    }

    printf("%d\n", max_points);
}