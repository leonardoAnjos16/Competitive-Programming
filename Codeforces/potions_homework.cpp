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
const int MOD = 1e4 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long a[MAX];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + a[i] * a[n - i - 1]) % MOD;

    cout << ans << "\n";
}