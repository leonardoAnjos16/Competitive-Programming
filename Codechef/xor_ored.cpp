#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int X = 0;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            for (int j = 0; j < 30; j++)
                if (A[i] & (1 << j))
                    X |= (1 << j);
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans |= A[i] ^ X;

        cout << X << " " << ans << "\n";
    }
}