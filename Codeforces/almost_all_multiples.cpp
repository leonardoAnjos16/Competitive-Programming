#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        if (n % x) cout << "-1\n";
        else {
            int div = n / x;
            vector<int> factors;

            for (int i = 2; i * i <= div; i++)
                while (!(div % i)) {
                    div /= i;
                    factors.push_back(i);
                }

            if (div > 1) factors.push_back(div);

            vector<int> ans(n + 1, 0);
            ans[1] = x;
            ans[n] = 1;

            int idx = x;
            for (int factor: factors) {
                ans[idx] = idx * factor;
                idx *= factor;
            }

            for (int i = 2; i < n; i++)
                if (!ans[i]) ans[i] = i;

            for (int i = 1; i <= n; i++) {
                if (i > 1) cout << " ";
                cout << ans[i];
            }

            cout << "\n";
        }
    }
}