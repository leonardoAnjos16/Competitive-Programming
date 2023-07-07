#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("grave.in", "r", stdin);
    freopen("grave.out", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int w, h;
    cin >> w >> h;

    bool possible = w <= x2 - x1 && h <= y2 - y4;
    possible |= w <= x3 - x1 && h <= y2 - y1;
    possible |= w <= x2 - x4 && h <= y2 - y1;
    possible |= w <= x2 - x1 && h <= y3 -  y1;

    cout << (possible ? "Yes" : "No") << "\n";
}