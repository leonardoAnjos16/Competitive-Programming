#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    int ans = n;
    for (int i = 1; i <= n / a; i++) {
        int j = (n - a * i) / b;
        if (j > i) ans = min(ans, n - a * i - b * j);
    }

    cout << ans << "\n";
}