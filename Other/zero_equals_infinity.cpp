#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1.0);

long double rat(int P, int S) {
    return P / (4 * S * tan(PI / S));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("polygon.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int P; long double X;
        cin >> P >> X;

        if (rat(P, 3) > X) {
            cout << "Khairy\n";
            continue;
        }

        if (P / (4 * PI) <= X) {
            cout << "KEE\n";
            continue;
        }

        int l = 1LL, r = 1e6 + 5, ans;
        while (l <= r) {
            int m = (l + r) / 2;
            if (rat(P, m) > X) r = m - 1;
            else l = m + 1, ans = m;
        }

        cout << ans << "\n";
    }
}