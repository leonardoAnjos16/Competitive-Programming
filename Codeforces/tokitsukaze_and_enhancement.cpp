#include <bits/stdc++.h>

using namespace std;

char category(int n) {
    if (n % 4 == 0) return 'D';
    if (n % 4 == 1) return 'A';
    if (n % 4 == 2) return 'C';
    return 'B';
}

int main() {
    int x; scanf("%d", &x);

    int a = 0;
    char b = category(x);

    for (int i = 1; i <= 2; i++) {
        char aux = category(x + i);
        if (aux < b) a = i, b = aux;
    }

    printf("%d %c\n", a, b);
}