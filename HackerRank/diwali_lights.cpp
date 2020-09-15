#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);

        int num_patterns = 1;
        while (N--) num_patterns = (num_patterns * 2) % MOD;

        printf("%d\n", --num_patterns);
    }
}