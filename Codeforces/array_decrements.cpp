#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool possible = true;
        int mn = INT_MIN, mx = INT_MAX;

        for (int i = 0; i < n && possible; i++) {
            if (a[i] < b[i]) possible = false;
            else {
                int curr_mn = a[i] - b[i];
                int curr_mx = !b[i] ? INT_MAX : curr_mn;

                if (curr_mx < mn || curr_mn > mx) possible = false;
                else {
                    mn = max(mn, curr_mn);
                    mx = min(mx, curr_mx);
                }
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}