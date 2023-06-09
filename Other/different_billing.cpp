#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    tuple<int, int, int> ans = make_tuple(-1, -1, -1);
    for (int b = 0; b < MAX && get<0>(ans) == -1; b++) {
        // 2500c = y - 1000b
        if (1000LL * b > y) continue;
        if ((y - 1000LL * b) % 2500LL) continue;

        int c = (y - 1000LL * b) / 2500LL;

        // a + b + c = x
        // a = x - b - c

        int a = x - b - c;
        if (a < 0) continue;

        ans = make_tuple(a, b, c);
    }

    auto [a, b, c] = ans;
    if (a == -1) cout << "-1\n";
    else cout << a << " " << b << " " << c << "\n";
}