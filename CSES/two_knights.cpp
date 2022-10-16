#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long long int ans = 0LL;
    for (int i = 2; i <= n; i++) {
        cout << ans << "\n";

        long long int extra = 0LL;
        for (int j = 1; j <= i; j++) {
            extra += 2LL * (i - 1LL) * (i - 1LL);
            if (j == i) extra -= (i - 1LL) * (i - 1LL);

            for (int k = 0; k < 8; k++) {
                if (i + dy[k] > 0 && i + dy[k] < i && j + dx[k] > 0 && j + dx[k] < i) {
                    extra -= 2;
                    if (j == i)
                        extra++;
                }
            }
        }
        
        extra += (2LL * i - 1LL) * (2LL * i - 2LL) / 2LL;
        if (i >= 3) extra -= 2LL;

        ans += extra;
    }

    cout << ans << "\n";
}