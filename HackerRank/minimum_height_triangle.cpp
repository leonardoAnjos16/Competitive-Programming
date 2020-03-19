#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int b, a;
    scanf("%lld %lld", &b, &a);

    long long int h = (2 * a) / b;
    if (h * b < 2 * a) h++;

    printf("%lld\n", h);
}