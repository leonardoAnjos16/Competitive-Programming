#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    set<int> aux;
    do {
        aux.insert(n++);
        while (n % 10 == 0) n /= 10;
    } while (!aux.count(n));

    int ans = aux.size();
    printf("%d\n", ans);
}