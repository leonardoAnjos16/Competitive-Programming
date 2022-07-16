#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong n; cin >> n;

    llong ans = abs(n - 1LL);
    for (llong first = 1LL; first * first <= n; first++)
        for (int diff = first > 1LL ? -1 : 0; diff <= 1; diff++) {
            llong second = first + diff;
            if (!(n % (first + second))) {
                llong rows = 2LL * n / (first + second);
                ans = min(ans, abs(rows - max(first, second)));
            } else if (!((n - first) % (first + second))) {
                llong rows = 2LL * (n - first) / (first + second) + 1LL;
                llong mx = rows > 1LL ? max(first, second) : first;
                ans = min(ans, abs(rows - mx));
            }
        }

    for (llong rows = 2LL; rows * rows <= n; rows++)
        for (int diff = -1; diff <= 1; diff++) {
            llong aux = n - diff * (rows / 2LL);
            if ((rows & 1LL) && !(aux % rows)) {
                // x * (r' + 1) + (x + d) * r' = n
                // x * r' + x + x * r' + d * r' = n
                // x * (2r' + 1) + d * r' = n
                // x = (n - d * r') / (2r' + 1)
                // x = (n - d * r') / (r + 1)

                llong first = aux / rows;
                llong second = first + diff;
                if (!first || !second) continue;
                ans = min(ans, abs(rows - max(first, second)));
            } else if (!(rows & 1LL) && !(aux % rows)) {
                // x * r' + (x + d) * r' = n
                // x * r' + x * r' + d * r' = n
                // 2x * r' + d * r' = n
                // x = (n - d * r') / 2r'
                // x = (n - d * r') / r

                llong first = aux / rows;
                llong second = first + diff;
                if (!first || !second) continue;
                ans = min(ans, abs(rows - max(first, second)));
            }
        }

    cout << ans << "\n";
}