#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("H.in", "r", stdin);

    int m; cin >> m;
    int n; cin >> n;

    int ans = (m + 1) * (n - 2);
    for (int i = 0; i <= m; i++)
        for (int j = i; j <= m; j++)
            for (int k = j; k <= m; k++)
                if (i * i + j * j == k * k) ans++;

    cout << ans << "\n";
}