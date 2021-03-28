#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

vi digits;
int memo[10][10][50][50];

int count(int i = 8, int tight = 1, int even = 0, int odd = 0) {
    if (i < 0) return even - odd == 1;

    int &ans = memo[i][tight][even][odd];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j <= (tight ? digits[i] : 9); j++) {
        if (i % 2) ans += count(i - 1, tight & (j == digits[i]), even + j, odd);
        else ans += count(i - 1, tight & (j == digits[i]), even, odd + j);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int from, to;
        cin >> from >> to;

        digits.assign(9, 0);
        memset(memo, -1, sizeof memo);

        int idx = 0;
        while (to) digits[idx++] = to % 10, to /= 10;

        int ans = count();
        digits.assign(9, 0);
        memset(memo, -1, sizeof memo);

        idx = 0; from--;
        while (from) digits[idx++] = from % 10, from /= 10;

        ans -= count();
        cout << ans << "\n";
    }
}