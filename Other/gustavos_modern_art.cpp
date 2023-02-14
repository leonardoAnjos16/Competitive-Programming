#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    bool h = false, v = false, md = false, sd = false;
    while (q--) {
        char c; cin >> c;

        if (c == 'r') {
            char type; cin >> type;
            if (type == 'a') md = !md;
            else if (type == 'c') sd = !sd;
            else if (type == 'b' && !(md ^ sd)) v = !v;
            else if (type == 'b') h = !h;
            else if (type == 'd' && !(md ^ sd)) h = !h;
            else if (type == 'd') v = !v;
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;

            if (md) {
                int diff = x - y;
                x -= diff;
                y += diff;
            }

            if (sd) {
                int diff = (n - x - 1) - y;
                x += diff;
                y += diff;
            }

            if (h) x = n - x - 1;
            if (v) y = n - y - 1;

            llong ans = 1LL * x * n + y + 1LL;
            cout << ans << "\n";
        }
    }
}