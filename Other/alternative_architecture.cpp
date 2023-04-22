#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong MAX = 1e9;

int sqrt(llong x) {
    int l = 0, r = min(x, MAX), ans = -1LL;
    while (l <= r) {
        int mid = (l + r) / 2LL;
        if (1LL * mid * mid > x) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    int ans = 0;
    for (int i = a - 1; i > 1 - a; i--) {
        llong goal = (a - 1LL) * (a - 1LL) - 1LL * i * i;
        int dx = sqrt(goal);

        if (1LL * dx * dx >= goal && (abs(i) * (b - 1LL)) % (a - 1) == 0 && (dx * (b - 1LL)) % (a - 1) == 0) ans++;
    }

    if (a == b) ans /= 2;
    cout << ans << "\n";
}