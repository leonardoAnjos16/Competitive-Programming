#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, K; scanf("%d %d", &N, &K);

        int index = 1 + (2 * K);
        if (index >= N) {
            index = N - 1;
            if (N % 2 == 0) index--;

            K -= N / 2;
            index -= 2 * K;
        }

        printf("%d\n", index);
    }
}