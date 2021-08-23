#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) swap(a, b);

        int diff = b - a;
        int sz = diff * 2;

        if (a > sz || b > sz || c > sz) cout << "-1\n";
        else {
            int ans = c > diff ? c - diff : c + diff;
            cout << ans << "\n";
        }
    }
}