#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c; scanf("%d %d", &r, &c);

    long long int init = --r / 2 * 10L;
    init += r % 2;

    long long int number = init + (--c * 2);
    printf("%lld\n", number);
}