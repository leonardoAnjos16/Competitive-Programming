#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    cin >> l >> r;

    int ans = 2 * max(l, r);
    if (!ans) cout << "Not a moose\n";
    else cout << (l == r ? "Even" : "Odd") << " " << ans << "\n";
}