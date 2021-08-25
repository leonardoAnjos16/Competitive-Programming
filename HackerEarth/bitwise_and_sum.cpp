#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int length[MAX] = {0};
        for (int i = 0; i < MAX; i++)
            for (int j = N - 1; j >= 0 && (A[j] & (1 << i)); j--)
                length[i]++;

        long ans = 0LL;
        int pand = (1 << MAX) - 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < MAX; j++)
                if (pand & (1 << j))
                    ans += 1LL * min(length[j], N - i - 1) * (1 << j);

            pand &= A[i];
            ans += pand;
        }

        ans -= pand;
        cout << ans << "\n";
    }
}