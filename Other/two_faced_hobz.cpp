#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("salkan.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int XA = 0;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            XA ^= A[i];
        }

        int basis[MAX] = {0};
        for (int i = 0; i < N; i++) {
            int B; cin >> B;

            int v = A[i] ^ B;
            bool done = false;

            for (int j = MAX - 1; j >= 0 && !done; j--) {
                if (!(v & (1 << j))) continue;

                if (basis[j]) v ^= basis[j];
                else basis[j] = v, done = true;
            }
        }

        int ans = XA;
        for (int i = MAX - 1; i >= 0; i--) {
            if (!basis[i]) continue;

            int aux = (ans & (1 << i)) ? ans : ans ^ basis[i];
            for (int j = i - 1; j >= 0; j--) {
                if (!basis[j]) continue;

                if (aux & (1 << j))
                    aux ^= basis[j];
            }

            if (aux > K && (ans & (1 << i))) ans ^= basis[i];
            else if (aux <= K && !(ans & (1 << i))) ans ^= basis[i];
        }

        if (ans > K) ans = 0;
        cout << ans << "\n";
    }
}