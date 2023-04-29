#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        bool found = false;
        for (int i = 0; i <= n && !found; i++) {
            int cnt = i * (i - 1) / 2;
            cnt += (n - i) * (n - i - 1) / 2;

            if (cnt == k) {
                found = true;
                cout << "YES\n";

                for (int j = 0; j < n; j++) {
                    if (j) cout << " ";
                    if (j < i) cout << "-1";
                    else cout << "1";
                }

                cout << "\n";
            }
        }

        if (!found) cout << "NO\n";
    }
}