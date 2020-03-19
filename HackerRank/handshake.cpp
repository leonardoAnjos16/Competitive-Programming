#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long long int N; scanf("%lld", &N);
        long long int handshakes = (N * (N - 1)) / 2;
        printf("%lld\n", handshakes);
    }
}