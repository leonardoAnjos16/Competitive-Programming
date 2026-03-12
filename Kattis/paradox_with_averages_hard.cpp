#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int Ncs, Ne;
        cin >> Ncs >> Ne;

        llong scs = 0LL;
        vector<int> cs(Ncs);

        for (int i = 0; i < Ncs; i++) {
            cin >> cs[i];
            scs += cs[i];
        }

        llong se = 0LL;
        vector<int> e(Ne);

        for (int i = 0; i < Ne; i++) {
            cin >> e[i];
            se += e[i];
        }

        int ans = 0;
        for (int i = 0; i < Ncs; i++)
            if (1LL * cs[i] * Ncs < scs && 1LL * cs[i] * Ne > se)
                ans++;

        cout << ans << "\n";
    }
}