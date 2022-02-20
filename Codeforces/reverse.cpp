#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int l = 0;
        while (p[l] == l + 1) l++;

        if (l >= n) {
            for (int i = 0; i < n; i++)
                cout << p[i] << " ";

            cout << "\n";
        } else {
            int r = l + 1;
            while (r < n && p[r] != l + 1) r++;

            for (int i = 0; i < l; i++)
                cout << p[i] << " ";

            for (int i = r; i >= l; i--)
                cout << p[i] << " ";

            for (int i = r + 1; i < n; i++)
                cout << p[i] << " ";

            cout << "\n";
        }
    }
}