#include <bits/stdc++.h>

using namespace std;

int x, y, z, a, b, c;

bool possible() {
    if (a < x) return false;
    a -= x;

    if (a + b < y) return false;
    int aux = min(a, y);
    a -= aux; y -= aux;
    b -= y;

    if (a + b + c < z) return false;
    else return true;
}

int main() {
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);

    printf("%s\n", possible() ? "YES" : "NO");
}