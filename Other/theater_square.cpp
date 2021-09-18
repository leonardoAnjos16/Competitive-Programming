#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int height = x2 - x1 + 1;

    int ans = (m & 1) * (n - height);
    ans += ((y1 - 1) & 1) * height;
    ans += ((m - y2) & 1) * height;

    ans = (ans + 1) / 2;
    cout << ans << "\n";
}