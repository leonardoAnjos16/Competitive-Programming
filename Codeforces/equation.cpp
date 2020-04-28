#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int main() {
    int n; scanf("%d", &n);

    int a = n + 4, b = 4;
    while (prime(a) || prime(b)) a++, b++;

    printf("%d %d\n", a, b);
}