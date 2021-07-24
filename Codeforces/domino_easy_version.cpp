#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (!(n % 2) && !(m % 2))
            cout << (!(k % 2) ? "YES" : "NO") << "\n";
        else {
            if (!(n % 2)) {
                swap(n, m);
                k = n * m / 2 - k;
            }

            if (k < m / 2) cout << "NO\n";
            else cout << (!((k - m / 2) % 2) ? "YES" : "NO") << "\n";
        }
    }
}