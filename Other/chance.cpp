#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

bool prime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++)
        if (!(x % i)) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt[MAX] = {0};
    for (int i = 1; i < MAX; i++)
        cnt[i] = cnt[i - 1] + (prime(__builtin_popcount(i)) ? 1 : 0);

    int T; cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;

        int ans = cnt[R];
        if (L) ans -= cnt[L - 1];
        cout << ans << "\n";
    }
}