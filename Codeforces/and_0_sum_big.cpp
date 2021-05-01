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
const int MOD = 1e9 + 7;

long exp(long b, long n) {
    if (!n) return 1LL;

    long ans = exp(b, n >> 1);
    ans = (ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (ans * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long n, k;
        cin >> n >> k;

        long ans = exp(n, k);
        cout << ans << "\n";
    }
}