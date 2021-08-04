#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int aux = 0;
        bool possible = false;

        while (aux <= n && !possible) {
            if (!((n - aux) % 2021)) possible = true;
            aux += 2020;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}