#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> digits;
vector<vector<vector<long>>> memo;

long rooms(int i = 0, bool small = true, bool last_one = false) {
    if (i >= (int) digits.size()) return 1LL;

    long &ans = memo[i][small][last_one];
    if (~ans) return ans;

    ans = 0LL;
    for (int j = 0; j <= (small ? digits[i] : 9); j++) {
        if (last_one && (j == 3)) continue;
        ans += rooms(i + 1, small && (j == digits[i]), j == 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hotel.in", "r", stdin);
    freopen("hotel.out", "w", stdout);

    int T; cin >> T;
    while (T--) {
        long N; cin >> N;

        long l = 1, r = 4e18, ans;
        while (l <= r) {
            long mid = (l + r) / 2LL;

            long aux = mid;
            digits.clear();

            while (aux) {
                digits.push_back(aux % 10LL);
                aux /= 10LL;
            }

            reverse(digits.begin(), digits.end());
            memo.assign(20, vector<vector<long>>(2, vector<long>(2, -1LL)));

            if (rooms() - 1LL < N) l = mid + 1LL;
            else r = mid - 1LL, ans = mid;
        }

        cout << ans << "\n";
    }
}