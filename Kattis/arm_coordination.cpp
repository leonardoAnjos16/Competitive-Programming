#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int r; cin >> r;

    cout << (x - r) << " " << (y + r) << "\n";
    cout << (x + r) << " " << (y + r) << "\n";
    cout << (x + r) << " " << (y - r) << "\n";
    cout << (x - r) << " " << (y - r) << "\n";
}