#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    if (x <= y) cout << (y - x) << "\n";
    else cout << (((x - y + 1) / 2) + ((x - y) % 2)) << "\n";
}