#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector<int> sums;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int sum = 0;
        for (int j = 0; j < (n / 2); j++)
            if (i & (1 << j)) sum = (sum + a[j]) % m;

        sums.push_back(sum);
    }

    int size = sums.size();
    sort(sums.begin(), sums.end());

    int max_sum = 0;
    for (int i = 0; i < (1 << (n - (n / 2))); i++) {
        int sum = 0;
        for (int j = 0; j < n - (n / 2); j++)
            if (i & (1 << j)) sum = (sum + a[j + (n / 2)]) % m;

        int idx = lower_bound(sums.begin(), sums.end(), m - sum) - sums.begin();
        idx = (idx + size - 1) % size;

        max_sum = max(max_sum, (sum + sums.back()) % m);
        max_sum = max(max_sum, (sum + sums[idx]) % m);
    }

    printf("%d\n", max_sum);
}