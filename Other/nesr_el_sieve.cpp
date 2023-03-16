#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("sieve.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;

        int na = A.size();
        int nb = B.size();
        int g = gcd(na, nb);

        vector<int> divs;
        for (int i = 1; i * i <= g; i++)
            if (!(g % i)) {
                divs.push_back(i);
                if (i * i < g)
                    divs.push_back(g / i);
            }

        int ans = 0;
        for (int div: divs) {
            bool possible = true;
            for (int i = 0; i < div && possible; i++)
                if (A[i] != B[i]) possible = false;

            for (int i = div; i < na && possible; i++)
                if (A[i] != A[i - div]) possible = false;

            for (int i = div; i < nb && possible; i++)
                if (B[i] != B[i - div]) possible = false;

            if (possible) ans = max(ans, div);
        }

        assert(ans);
        cout << ans << "\n";
    }
}