#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        bool beautiful = false;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (i >= a - 1)
                beautiful = true;
        }

        cout << (beautiful ? "YES" : "NO") << "\n";
    }
}