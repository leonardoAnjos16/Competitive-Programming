#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int sum(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string n; cin >> n;

        int x = 0, y = 0;
        bool left = true;

        for (char c: n) {
            int d = c - '0';
            x *= 10; y *= 10;

            if (!(d & 1)) {
                x += d / 2;
                y += d / 2;
            } else if (left) {
                x += d / 2 + 1;
                y += d / 2;
                left = false;
            } else {
                x += d / 2;
                y += d / 2 + 1;
                left = true;
            }
        }

        cout << x << " " << y << "\n";
    }
}