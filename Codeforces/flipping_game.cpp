#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    // O(n²)
    /* int n; scanf("%d", &n);

    int A[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        A[i] += A[i - 1];
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int sum = A[j] - A[i - 1];
            ans = max(ans, A[n] - sum + j - i + 1 - sum);
        }

    printf("%d\n", ans); */

    // O(n)
    int n; scanf("%d", &n);

    int A[MAX], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
        A[i] = A[i] ? -1 : 1;
    }

    int ans = INT_MIN, curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += A[i];
        ans = max(ans, curr_sum);
        if (curr_sum < 0) curr_sum = 0;
    }

    ans += sum;
    printf("%d\n", ans);
}