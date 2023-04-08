#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int q; cin >> q;

        llong l = 1LL, r = 1e18 + 5;
        for (int i = 0; i < q; i++) {
            if (i) cout << " ";

            int type; cin >> type;
            if (type == 1) {
                int a, b, n;
                cin >> a >> b >> n;

                llong nl = n == 1 ? 1LL : (n - 2LL) * (a - b) + a + 1LL;
                llong nr = (n - 1LL) * (a - b) + a;

                if (nr < l || nl > r) cout << "0";
                else {
                    cout << "1";
                    l = max(l, nl);
                    r = min(r, nr);
                }
            } else {
                int a, b;
                cin >> a >> b;

                llong lo = 1LL, hi = 1e18 + 5, nl = -1LL;
                while (lo <= hi) {
                    llong mid = (lo + hi) / 2LL;
                    if (mid - 1LL < (l - b - 1LL) / (a - b)) lo = mid + 1LL;
                    else hi = mid - 1LL, nl = mid;
                }

                lo = 1LL; hi = 1e18 + 5; llong nr = -1LL;
                while (lo <= hi) {
                    llong mid = (lo + hi) / 2LL;
                    if (mid - 1LL < (r - b - 1LL) / (a - b)) lo = mid + 1LL;
                    else hi = mid - 1LL, nr = mid;
                }

                assert(nl > 0LL && nl <= nr);
                if (nl < nr) cout << "-1";
                else cout << nl;
            }
        }

        cout << "\n";
    }
}