#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 105;
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
 
        int A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
 
        sort(A, A + n);
 
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n / 2; i++) {
            int sum = A[i] + A[n - i - 1];
            low = min(low, sum);
            high = max(high, sum);
        }
 
        int ans = high - low;
        printf("%d\n", ans);
    }
}