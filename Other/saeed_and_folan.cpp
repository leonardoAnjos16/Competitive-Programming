#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int L1, R1, p1, D1;
        cin >> L1 >> R1 >> p1 >> D1;

        int L2, R2, p2, D2;
        cin >> L2 >> R2 >> p2 >> D2;

        int K; cin >> K;

        int ans = (p1 == p2);
        while (K--) {
            if ((p1 == L1 && !D1) || (p1 == R1 && D1)) D1 = 1 - D1;
            if ((p2 == L2 && !D2) || (p2 == R2 && D2)) D2 = 1 - D2;

            if (D1) p1++;
            else p1--;

            if (D2) p2++;
            else p2--;

            if (p1 == p2) ans++;
        }

        cout << ans << "\n";
    }
}