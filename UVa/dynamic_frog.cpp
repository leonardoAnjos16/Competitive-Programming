#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N, D; scanf("%d %d\n", &N, &D);

        char S[MAX]; int M[MAX];
        S[0] = S[N + 1] = 'B';
        M[0] = 0; M[N + 1] = D;

        for (int j = 1; j <= N; j++)
            scanf("%c-%d\n", &S[j], &M[j]);

        int ans = INT_MIN;
        for (int j = 0; j <= N; j++) {
            if (S[j + 1] == 'B') ans = max(ans, M[j + 1] - M[j]);
            else ans = max(ans, M[j + 2] - M[j]);
        }

        printf("Case %d: %d\n", i, ans);
    }
}