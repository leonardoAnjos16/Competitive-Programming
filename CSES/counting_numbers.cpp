#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> digits;
long memo[2][2][20][20];

long count(bool tight = true, bool zero = true, int i = 0, int last = 0) {
    if (i >= (int) digits.size()) return 1LL;

    long &ans = memo[tight][zero][i][last];
    if (~ans) return ans;

    ans = 0LL;
    for (int j = 0; j <= (tight ? digits[i] : 9); j++)
        if (j != last || (!last && zero))
            ans += count(tight && j == digits[i], zero && !j, i + 1, j);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a, b;
    cin >> a >> b;

    while (b) {
        digits.push_back(b % 10LL);
        b /= 10LL;
    }

    reverse(digits.begin(), digits.end());
    memset(memo, -1, sizeof memo);

    long ans = count();
    if (a--) {
        digits.clear();
        while (a) {
            digits.push_back(a % 10LL);
            a /= 10LL;
        }

        reverse(digits.begin(), digits.end());
        memset(memo, -1, sizeof memo);

        ans -= count();
    }

    cout << ans << "\n";
}