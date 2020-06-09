#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, K; scanf("%d %d", &N, &K);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int P; scanf("%d", &P);
            if (P > K) ans += P - K;
        }

        printf("%d\n", ans);
    }
}