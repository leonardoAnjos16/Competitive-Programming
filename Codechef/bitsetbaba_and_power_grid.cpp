#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int K, M;
        cin >> K >> M;

        int sz = 0;
        vector<int> basis(K, 0);

        for (int i = 0; i < M; i++) {
            int x; cin >> x;

            bool done = false;
            for (int j = 0; j < K && !done; j++) {
                if (!(x & (1 << j))) continue;

                if (basis[j]) x ^= basis[j];
                else basis[j] = x, sz++, done = true;
            }
        }

        int ans = 1 << (K - sz);
        cout << ans << "\n";
    }
}