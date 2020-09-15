#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n, t; scanf("%d %d", &n, &t);

    int sum[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    int max_books = 0;
    for (int i = 0; i < n; i++) {
        int idx = upper_bound(sum, sum + n + 1, sum[i] + t) - sum - 1;
        max_books = max(max_books, idx - i);
    }

    printf("%d\n", max_books);
}