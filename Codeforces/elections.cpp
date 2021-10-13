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

        int e = max(max(b, c) + 1 - a, 0);
        int f = max(max(a, c) + 1 - b, 0);
        int g = max(max(a, b) + 1 - c, 0);

        cout << e << " " << f << " " << g << "\n";
    }
}