#include <bits/stdc++.h>

using namespace std;

#define long long long int

int pow(int a, int n) {
    if (!n) return 1;
    else return a * pow(a, n - 1);
}

int main() {
    int X; long N;
    scanf("%d %lld\n", &X, &N);

    int aux[5] = {1};
    for (int i = 1; i < 5; i++)
        aux[i] = aux[i - 1] * i;

    int exp = N < 5 ? aux[N] % 10 : 0;
    int ans = pow(X % 10, exp) % 10;

    printf("%lld\n", ans);
}