#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        
        int mult = b * ((a / b) + ((a % b) ? 1 : 0));

        int moves = mult - a;
        printf("%d\n", moves);
    }
}