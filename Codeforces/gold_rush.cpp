#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int divs = 0;
        bool possible = false;

        while (!possible) {
            int mults = 0, aux = m;
            while (aux < n) {
                mults++;
                aux *= 3;
            }

            if (aux == n && mults >= divs) possible = true;
            else if (m & 1) break;
            else m >>= 1, divs++;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}