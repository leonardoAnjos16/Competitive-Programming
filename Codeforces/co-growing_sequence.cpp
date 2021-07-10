#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        int last = x[0];
        vector<int> y(n, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 30; j++)
                if ((last & (1 << j)) && !(x[i] & (1 << j)))
                    y[i] |= (1 << j);

            last = x[i] ^ y[i];
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << y[i];
        }

        cout << "\n";
    }
}