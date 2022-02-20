#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;
    cin >> x >> y >> z;

    if (x > y + z) cout << "+\n";
    else if (y > x + z) cout << "-\n";
    else if (x == y && !z) cout << "0\n";
    else cout << "?\n";
}