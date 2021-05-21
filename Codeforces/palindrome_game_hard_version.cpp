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

const int MAX = 1e3 + 5;

int memo[MAX][MAX][2];

int dollars(int sz, int nsz, int rev = 0) {
    if (!(sz + nsz)) return 0;

    int &ans = memo[sz][nsz][rev];
    if (~ans) return ans;

    ans = INT_MAX;
    if (nsz && !rev) ans = min(ans, -dollars(sz, nsz, 1));
    if (sz & 1) ans = min(ans, 1 - dollars(sz - 1, nsz));
    if (sz > 1) ans = min(ans, 1 - dollars(sz - 2, nsz + 1));
    if (nsz) ans = min(ans, 1 - dollars(sz, nsz - 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    memset(memo, -1, sizeof memo);

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int sz = 0, nsz = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (s[n - i - 1] == '0') sz++;
                else nsz++;
            }
        }

        int aux = dollars(sz, nsz);
        if (aux < 0) cout << "ALICE\n";
        else if (aux > 0) cout << "BOB\n";
        else cout << "DRAW\n";
    }
}