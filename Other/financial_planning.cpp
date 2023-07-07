#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    cin >> n >> M;

    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> c[i];

    llong l = 1, r = 3e9 + 5, ans = -1;
    while (l <= r) {
        llong mid = (l + r) / 2;

        llong sum = 0LL;
        for (int i = 0; i < n && sum < M; i++)
            if (1LL * mid * p[i] >= c[i])
                sum += 1LL * mid * p[i] - c[i];

        if (sum < M) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}