#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int M; cin >> M;

        int x = 0;
        for (int i = 0; i < M; i++) {
            int S;
            cin >> S;
            x ^= S;
        }

        int ans = !x ? 1 : 0;
        cout << ans << "\n";
    }
}