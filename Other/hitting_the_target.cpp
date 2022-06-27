#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; cin >> R;

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;

        int circle = 1;
        while (circle <= 10 && x * x + y * y > circle * circle * R * R)
            circle++;

        if (circle <= 10) ans += 10 - circle + 1;
    }

    cout << ans << "\n";
}