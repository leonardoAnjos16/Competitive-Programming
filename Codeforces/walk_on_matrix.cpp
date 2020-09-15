#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 17;

int main() {
    int k; scanf("%d", &k);

    printf("2 3\n");
    printf("%d %d %d\n", MAX + k, k, 0);
    printf("%d %d %d\n", MAX, MAX + k, k);
}