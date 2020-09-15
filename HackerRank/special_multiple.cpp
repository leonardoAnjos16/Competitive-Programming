#include <bits/stdc++.h>

using namespace std;

long long int get_number(long long int mask) {
    long long int number = 0;
    for (int i = 0; i < 64; i++)
        if (mask & (1L << i))
            number += 9L * pow(10, i);

    return number;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long long int N; scanf("%lld", &N);

        long long int mask = 1, X;
        do X = get_number(mask++);
        while (X % N);

        printf("%lld\n", X);
    }
}