#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long n, m, x;
        cin >> n >> m >> x;

        x--;
        long row = x % n;
        long col = x / n;

        long ans = row * m + col + 1;
        cout << ans << "\n";
    }
}