#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hanya.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        bool pos = false, neg = false;
        for (int i = 0; i < N; i++) {
            int A; cin >> A;
            if (A > 0) pos = true;
            else if (A < 0) neg = true;
        }

        int ans = pos + neg;
        cout << ans << "\n";
    }
}