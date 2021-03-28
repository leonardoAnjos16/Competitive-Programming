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

const int MAX = 15;

vi digits;
long sums[MAX][MAX];
long counts[MAX][MAX];

long count(int i, int tight) {
    if (i > 9) return 1LL;

    long &ans = counts[i][tight];
    if (~ans) return ans;

    ans = 0LL;
    for (int j = 0; j <= (tight ? digits[i] : 9); j++)
        ans += count(i + 1, tight & (j == digits[i]));

    return ans;
}

long sum(int i = 0, int tight = 1) {
    if (i > 9) return 0LL;

    long &ans = sums[i][tight];
    if (~ans) return ans;

    ans = 0LL;
    for (int j = 0; j <= (tight ? digits[i] : 9); j++)
        ans += j * count(i + 1, tight & (j == digits[i])) + sum(i + 1, tight & (j == digits[i]));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (cin >> a >> b, ~a | ~b) {
        digits.clear();
        digits.assign(10, 0);
        memset(sums, -1, sizeof sums);
        memset(counts, -1, sizeof counts);

        int idx = 9;
        while (b) digits[idx--] = b % 10, b /= 10;

        long ans = sum();

        digits.clear();
        digits.assign(10, 0);
        memset(sums, -1, sizeof sums);
        memset(counts, -1, sizeof counts);

        idx = 9; a--;
        while (a) digits[idx--] = a % 10, a /= 10;

        ans -= sum();
        cout << ans << "\n";
    }
}