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
const int MOD = 1e7 + 7;

long pot(long b, long n) {
    if (n == 1) return b;

    long aux = pot(b, n / 2);
    long square = (aux * aux) % MOD;

    if (!(n % 2)) return square;
    return (square * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k;
    while (cin >> n >> k, n || k) {
        long ans = (2 * pot(n - 1, k)) % MOD;

        ans += (2 * pot(n - 1, n - 1)) % MOD;
        ans %= MOD;

        ans += pot(n, k);
        ans %= MOD;

        ans += pot(n, n);
        ans %= MOD;

        cout << ans << "\n";
    }
}