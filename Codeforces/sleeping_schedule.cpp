#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3 + 5;

bool in_interval(int v, int l, int r) {
    return v >= l && v <= r;
}

int main() {
    int n, h, l, r;
    scanf("%d %d %d %d", &n, &h, &l, &r);

    int A[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    vector< vector<int> > max_good(n + 1);
    for (int i = 0; i <= n; i++)
        max_good[i].assign(i + 1, 0);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        for (int j = 0; j <= i; j++) {
            max_good[i + 1][j] = max(max_good[i + 1][j], max_good[i][j] + in_interval((sum - j) % h, l, r));
            max_good[i + 1][j + 1] = max(max_good[i + 1][j + 1], max_good[i][j] + in_interval((sum - j - 1) % h, l, r));
        }
    }

    int best = INT_MIN;
    for (int i = 0; i <= n; i++)
        best = max(best, max_good[n][i]);

    printf("%d\n", best);
}