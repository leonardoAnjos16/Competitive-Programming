#include <bits/stdc++.h>

using namespace std;

int count_divs(int N) {
    int num_divs = 0;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i % 2 == 0) num_divs++;

            int other_div = N / i;
            if (other_div != i && other_div % 2 == 0) num_divs++;
        }
    }

    return num_divs;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        printf("%d\n", count_divs(N));
    }
}