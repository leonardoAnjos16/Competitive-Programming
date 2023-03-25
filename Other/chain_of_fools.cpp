#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, c, p, l, t = 1;
    while (cin >> s >> c >> p >> l, s || c || p || l) {
        cout << "Case " << t++ << ": ";

        int m = (s - p) % s, r = 0;
        while (r < c && (r * s) % c != ((c - m - l) % c + c) % c) r++;

        if (r >= c) cout << "Never\n";
        else cout << r << " " << m << "/" << s << "\n";
    }
}