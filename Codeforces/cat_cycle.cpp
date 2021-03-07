#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n % 2 == 0) cout << (k % n ? k % n : n) << "\n";
        else {
            int extra = (k - 1) / (n / 2);

            int ans = (k + extra) % n;
            if (!ans) ans = n;

            cout << ans << "\n";
        }
    }
}