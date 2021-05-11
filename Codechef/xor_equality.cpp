#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

long exp(int b, int n) {
    if (!n) return 1LL;

    long ans = exp(b, n >> 1);
    ans = (ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (ans * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        long ans = exp(2, N - 1);
        cout << ans << "\n";
    }
}