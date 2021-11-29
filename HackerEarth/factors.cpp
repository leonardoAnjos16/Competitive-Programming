#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<int> B(N);
        for (int i = 0; i < N; i++)
            cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        long mn = 1LL, mx = 1LL;
        for (int i = 0; i < N; i++) {
            mn = (mn * (A[i] + B[i] + 1)) % MOD;
            mx = (mx * (A[i] + 1)) % MOD;
            mx = (mx * (B[i] + 1)) % MOD;
        }

        cout << mn << " " << mx << "\n";
    }
}