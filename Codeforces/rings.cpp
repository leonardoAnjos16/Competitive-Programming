#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int zero = 0;
        while (zero < n && s[zero] != '0') zero++;

        int l1, r1, l2, r2;
        if (zero < (n + 1) / 2) {
            l1 = zero + 1; r1 = n;
            l2 = zero + 2; r2 = n;
        } else if (zero < n) {
            l1 = 1; r1 = zero + 1;
            l2 = 1; r2 = zero;
        } else {
            l1 = 1; r1 = n - 1;
            l2 = 2; r2 = n;
        }

        cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
    }
}