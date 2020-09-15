#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int m[MAX], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        sum += m[i];
    }

    int mid = sum / n;
    sort(m, m + n);

    vector<int> sol(n, mid);
    for (int i = 1; i <= sum % n; i++)
        sol[n - i]++;

    int ans = 0, idx = 0;
    while (idx < n && m[idx] <= sol[idx])
        ans += sol[idx] - m[idx], idx++;

    printf("%d\n", ans);
}