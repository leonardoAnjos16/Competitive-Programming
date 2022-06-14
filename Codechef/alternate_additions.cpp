#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        long mn = -1LL;
        int l = 1, r = 1e9 + 5;

        while (l <= r) {
            int mid = (l + r) / 2;

            int ones = (mid + 1) / 2;
            int twos = mid - ones;

            if (A + ones + 2LL * twos < B) l = mid + 1;
            else r = mid - 1, mn = A + ones + 2LL * twos;
        }

        bool possible = mn == B;
        cout << (possible ? "YES" : "NO") << "\n";
    }
}