#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n == 4 && k == 3) cout << "-1\n";
        else if (k == n - 1) {
            cout << "1 3\n";
            cout << "0 " << (n - 4) << "\n";
            cout << (n - 2) << " " << (n - 1) << "\n";

            int l = 2, r = n - 3;
            while (l < r) {
                if (l != 3 && r != n - 4)
                    cout << l << " " << r << "\n";

                l++; r--;
            }
        } else {
            cout << k << " " << (n - 1) << "\n";
            if (k) cout << "0 " << (n - k - 1) << "\n";

            int l = 1, r = n - 2;
            while (l < r) {
                if (l != k && r != k)
                    cout << l << " " << r << "\n";

                l++; r--;
            }
        }
    }
}