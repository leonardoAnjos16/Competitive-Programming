#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N; scanf("%d %d", &M, &N);
    if (M < N) swap(M, N);

    int ans = N * (M / 2) + (N / 2) * (M % 2);
    printf("%d\n", ans);
}