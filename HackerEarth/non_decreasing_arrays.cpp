#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<long> B(N);
        B[0] = A[0];

        for (int i = 1; i < N; i++)
            B[i] = (B[i - 1] + A[i] - 1) / A[i] * A[i];

        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << B[i];
        }

        cout << "\n";
    }
}