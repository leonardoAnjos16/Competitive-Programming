#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N; scanf("%d", &N);

        do N -= 5;
        while (N > 0 && N % 3);

        if (N <= 0) N = -1;
        printf("Case %d: %d\n", i, N);
    }
}