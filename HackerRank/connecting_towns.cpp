#include <bits/stdc++.h>

using namespace std;

const int MOD = 1234567;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        int num_routes = 1;
        while (--N) {
            int Ni; scanf("%d", &Ni);
            num_routes *= Ni;
            num_routes %= MOD;
        }

        printf("%d\n", num_routes);
    }
}