#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);

    int t = ceil(c * (a - b) / (b + 0.0));
    printf("%d\n", t);
}