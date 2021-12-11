#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    for (int i = 0; i <= k; i++)
        if (i <= n && !((k - i) % 2) && (k - i) / 2 <= m)
            ans++;

    cout << ans << "\n";
}