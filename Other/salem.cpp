#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int ans = INT_MIN;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                int dist = 0;
                for (int k = 0; k < 32; k++)
                    dist += (A[i] & (1 << k)) != (A[j] & (1 << k));

                ans = max(ans, dist);
            }

        cout << ans << "\n";
    }
}