#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX_BASE = 12;
const int MAX_LEN = 80;

long memo[MAX_BASE][MAX_LEN][1 << MAX_BASE];

int convert(long n, int b, vector<int> &digits) {
    digits.clear();
    if (!n) digits.push_back(0);
    while (n) {
        digits.push_back(n % b);
        n /= b;
    }

    reverse(digits.begin(), digits.end());
    return (int) digits.size();
}

long magic(int base, int len, int mask = 0) {
    if (!len) return 0LL;
    if (len == 1) {
        int cnt = 0;
        for (int i = 0; i < base; i++)
            if (mask & (1 << i)) cnt++;

        return cnt == 1;
    }

    long &ans = memo[base][len][mask];
    if (~ans) return ans;

    ans = 0LL;
    for (int i = 0; i < base; i++)
        ans += magic(base, len - 1, mask ^ (1 << i));

    return ans;
}

long magic(long n, int b) {
    vector<int> digits;
    int num_digits = convert(n, b, digits);

    long ans = 0LL;
    for (int i = 1; i < num_digits; i++)
        ans += magic(b, i) - magic(b, i - 1, 1);

    int aux = 0;
    for (int i = 0; i < num_digits - 1; i++) {
        for (int j = (!i ? 1 : 0); j < digits[i]; j++)
            ans += magic(b, num_digits - i - 1, aux ^ (1 << j));

        aux ^= (1 << digits[i]);
    }

    for (int i = 0; i <= digits[num_digits - 1]; i++)
        if (!(aux ^ (1 << i))) ans++;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    int q; cin >> q;
    while (q--) {
        int b; long l, r;
        cin >> b >> l >> r;

        long ans = magic(r, b);
        ans -= magic(l - 1LL, b);
        cout << ans << "\n";
    }
}