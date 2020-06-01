#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX_SUM = 4e3 + 5;
const int MAX_N = 205;
const int MAX_M = 25;

int A[MAX_N], N, D;
long memo[MAX_SUM][MAX_N][MAX_M];

int mod(int n, int m) {
    return ((n % m) + m) % m;
}

long groups(int sum, int i, int rem) {
    if (!rem && !sum) return 1LL;
    if (!rem || i >= N) return 0LL;
    if (memo[sum][i][rem] != -1) return memo[sum][i][rem];
    return memo[sum][i][rem] = groups(sum, i + 1, rem) + groups(mod(sum + mod(A[i], D), D), i + 1, rem - 1);
}

int main() {
    int Q, case_num = 1;
    while (scanf("%d %d", &N, &Q), N | Q) {
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        printf("SET %d:\n", case_num++);
        for (int i = 1; i <= Q; i++) {
            int M; scanf("%d %d", &D, &M);
            memset(memo, -1, sizeof memo);

            long ans = groups(0, 0, M);
            printf("QUERY %d: %lld\n", i, ans);
        }
    }
}