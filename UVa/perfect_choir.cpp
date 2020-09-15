#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int A[MAX], sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }

        if (sum % N) printf("-1\n");
        else {
            int ans = 1, mid = sum / N;
            for (int i = 0; i < N && A[i] < mid; i++)
                ans += mid - A[i];

            printf("%d\n", ans);
        }
    }
}