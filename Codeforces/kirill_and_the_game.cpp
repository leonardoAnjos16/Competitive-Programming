#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;

    bool possible = false;
    for (int i = l; i <= r && !possible; i++) {
        if (i % k) continue;
        if (i / k < x || i / k > y) continue;
        possible = true;
    }

    cout << (possible ? "YES" : "NO") << "\n";
}