#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int N;
    while (scanf("%d", &N), N) {
        int A[MAX];
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }

        if (ans <= 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", ans);
    }
}