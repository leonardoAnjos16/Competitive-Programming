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
        bool neg = false, pos = false;

        for (int i = 0; i < n && possible; i++) {
            if (a[i] < b[i] && !pos) possible = false;
            else if (a[i] > b[i] && !neg) possible = false;

            if (a[i] == -1) neg = true;
            else if (a[i] == 1) pos = true;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}