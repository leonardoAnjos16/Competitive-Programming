#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int std; cin >> std;
    int d = std % 10; std /= 10;

    int s, t;
    if (std >= 1000) {
        t = std % 10; std /= 10;
        t += (std % 10) * 10; std /= 10;

        s = std % 10; std /= 10;
        s += std * 10;
    } else if (std >= 100) {
        t = std % 10; std /= 10;
        if (!(std % 10) || t >= 2) {
            s = std % 10; std /= 10;
            s += std * 10;
        } else {
            t += (std % 10) * 10; std /= 10;
            s = std;
        }
    } else {
        t = std % 10; std /= 10;
        s = std;
    }

    int ans = (12 + t - s) * d;
    cout << ans << "\n";
}