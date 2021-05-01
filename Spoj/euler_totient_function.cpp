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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        long ans = n;
        for (int i = 2; i * i <= n; i++) {
            if (!(n % i)) ans /= i, ans *= (i - 1);
            while (!(n % i)) n /= i;
        }

        if (n > 1)
            ans /= n, ans *= (n - 1);
            
        cout << ans << "\n";
    }
}