#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; cin >> X;

    int ans = min((3000 + X - 1) / X, 15);
    cout << ans << "\n";
}