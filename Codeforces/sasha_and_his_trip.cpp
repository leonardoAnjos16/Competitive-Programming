#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v; scanf("%d %d", &n, &v);

    int money = min(n - 1, v);
    int aux = n - money;
    money += (aux * (aux + 1) / 2) - 1;

    printf("%d\n", money);
}