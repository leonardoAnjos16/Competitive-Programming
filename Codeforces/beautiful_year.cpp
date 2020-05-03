#include <bits/stdc++.h>

using namespace std;

bool all_diff(int n) {
    bitset<10> used;
    while (n) {
        if (used[n % 10]) return false;
        used[n % 10] = true;
        n /= 10;
    }

    return true;
}

int main() {
    int y; scanf("%d", &y);
    
    while (!all_diff(++y));
    printf("%d\n", y);
}