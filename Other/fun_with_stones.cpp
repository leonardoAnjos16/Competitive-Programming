#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;
const int MOD = 1e9 + 7;

int memo[2][8][MAX];

int win(int a, int b, int c, bool pos = false, int tight = 7, int i = MAX - 1) {
    if (i < 0) return pos;

    int &ans = memo[pos][tight][i];
    if (~ans) return ans;

    ans = 0;
    for (int digits = 0; digits < 8; digits++) {
        if ((tight & 1) && (digits & 1) && !(a & (1 << i))) continue;
        if ((tight & 2) && (digits & 2) && !(b & (1 << i))) continue;
        if ((tight & 4) && (digits & 4) && !(c & (1 << i))) continue;

        bool atight = (tight & 1) && !!(digits & 1) == !!(a & (1 << i));
        bool btight = (tight & 2) && !!(digits & 2) == !!(b & (1 << i));
        bool ctight = (tight & 4) && !!(digits & 4) == !!(c & (1 << i));

        bool npos = pos || (__builtin_popcount(digits) & 1);
        int ntight = atight | (btight << 1) | (ctight << 2);

        ans = (ans + win(a, b, c, npos, ntight, i - 1)) % MOD;
    }

    return ans;
}

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return exp(a, m - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L[3], R[3];
    for (int i = 0; i < 3; i++)
        cin >> L[i] >> R[i];

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        memset(memo, -1, sizeof memo);

        int a = i & 1 ? L[0] - 1 : R[0];
        int b = i & 2 ? L[1] - 1 : R[1];
        int c = i & 4 ? L[2] - 1 : R[2];

        int curr = win(a, b, c);
        if (__builtin_popcount(i) & 1) curr = (MOD - curr) % MOD;
        ans = (ans + curr) % MOD;
    }

    int total = R[0] - L[0] + 1;
    total = (total * (R[1] - L[1] + 1LL)) % MOD;
    total = (total * (R[2] - L[2] + 1LL)) % MOD;

    ans = (1LL * ans * mod_mult_inv(total, MOD)) % MOD;
    cout << ans << "\n";
}