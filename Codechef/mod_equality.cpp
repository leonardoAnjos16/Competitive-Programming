#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int mn = INT_MAX;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            mn = min(mn, A[i]);
        }

        int ans = N, cnt = 0;
        bool possible = true;

        for (int i = 0; i < N && possible; i++) {
            if (A[i] == mn) cnt++;
            else if ((A[i] + 1) / 2 - 1 < mn)
                possible = false;
        }

        if (possible) ans = N - cnt;
        cout << ans << "\n";
    }
}