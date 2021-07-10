#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N + 1);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        A[N] = -1;

        int ans = 0, idx = 0;
        while (idx < N) {
            if (A[idx + 1] < A[idx])
                ans++;

            idx++;
        }

        cout << ans << "\n";
    }
}