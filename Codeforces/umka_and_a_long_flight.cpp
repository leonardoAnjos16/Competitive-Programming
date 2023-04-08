#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 46;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong fibs[MAX] { 1, 1 };
    for (int i = 2; i < MAX; i++)
        fibs[i] = fibs[i - 1] + fibs[i - 2];

    int t; cin >> t;
    while (t--) {
        int n; llong x, y;
        cin >> n >> x >> y;

        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            if (!(i & 1)) {
                if (y > fibs[n - i]) y -= fibs[n - i];
                else if (y <= fibs[n - i - 1]) continue;
                else possible = false;
            } else {
                if (x > fibs[n - i]) x -= fibs[n - i];
                else if (x <= fibs[n - i - 1]) continue;
                else possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}