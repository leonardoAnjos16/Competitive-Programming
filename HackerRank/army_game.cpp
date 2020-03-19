#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    int h = (n / 2) + (n % 2);
    int w = (m / 2) + (m % 2);

    int min_supplies = h * w;
    printf("%d\n", min_supplies);
}