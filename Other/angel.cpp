#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n == 1) cout << "1\n1\n";
    else if (n == 2) cout << "2\n2 2\n";
    else {
        int ans = 2 * (n - 2);
        cout << ans << "\n";

        for (int i = 2; i < n; i++)
            cout << i << " ";

        if (n & 1)
            for (int i = 2; i < n; i++) {
                if (i > 2) cout << " ";
                cout << i;
            }
        else
            for (int i = n - 1; i >= 2; i--) {
                if (i < n - 1) cout << " ";
                cout << i;
            }

        cout << "\n";
    }
}