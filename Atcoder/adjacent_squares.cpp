#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    int R, C;
    cin >> R >> C;

    int ans = 0;
    if (R - 1 > 0) ans++;
    if (R + 1 <= H) ans++;
    if (C - 1 > 0) ans++;
    if (C + 1 <= W) ans++;

    cout << ans << "\n";
}