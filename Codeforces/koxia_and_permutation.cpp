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

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            int pi = i & 1 ? i / 2 + 1 : n - i / 2;
            cout << pi;
        }

        cout << "\n";
    }
}