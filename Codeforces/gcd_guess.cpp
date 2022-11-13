#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            int b = (1 << i) - ans;
            int a = (1 << (i + 1)) + b;

            cout << "? " << a << " " << b << "\n";
            cout.flush();

            int g; cin >> g;
            if (g == 1 << (i + 1))
                ans |= 1 << i;
        }

        cout << "! " << ans << "\n";
        cout.flush();
    }
}