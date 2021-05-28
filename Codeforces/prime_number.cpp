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

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

long exp(long b, long n) {
    if (!n) return 1LL;

    long ans = exp(b, n >> 1LL);
    ans = (ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (ans * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long x;
    cin >> n >> x;

    long a[MAX], sum = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    map<long, int> cnt;
    for (int i = 0; i < n; i++)
        cnt[sum - a[i]]++;

    while (!(cnt.begin()->snd % x)) {
        int aux = cnt.begin()->snd / x;
        cnt[cnt.begin()->fst + 1] += aux;
        cnt.erase(cnt.begin());
    }

    long mn_exp = min(cnt.begin()->fst, sum);
    long ans = exp(x, mn_exp);
    cout << ans << "\n";
}