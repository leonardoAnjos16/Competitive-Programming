#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    cout << "? 1 " << n << "\n";
    cout.flush();

    int i; cin >> i;

    if (n == 2) {
        cout << "! " << (3 - i) << "\n";
        cout.flush();
    } else {
        int j = -1;
        if (i > 1) {
            cout << "? 1 " << i << "\n";
            cout.flush();

            cin >> j;
        }

        bool left = i == j;
        int l = left ? 1 : i + 1;
        int r = left ? i - 1 : n;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            cout << "? " << (left ? mid : i) << " " << (left ? i : mid) << "\n";
            cout.flush();

            cin >> j;

            if (i != j) {
                if (left) r = mid - 1;
                else l = mid + 1;
            } else {
                ans = mid;
                if (left) l = mid + 1;
                else r = mid - 1;
            }
        }

        assert(ans != -1);
        
        cout << "! " << ans << "\n";
        cout.flush();
    }
}