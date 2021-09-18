#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int zero = 0;
        vector<long> A(N);
        vector<int> pos;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            zero += !A[i];
            if (A[i]) pos.push_back(i);
        }

        if (zero == N) cout << "0\n";
        else {
            while (zero && K) {
                vector<int> new_pos;
                for (auto p: pos) {
                    if (!A[(p + 1) % N]) {
                        zero--;
                        new_pos.push_back((p + 1) % N);
                    }

                    if (!A[(p - 1 + N) % N]) {
                        zero--;
                        new_pos.push_back((p - 1 + N) % N);
                    }

                    A[(p + 1) % N]++;
                    A[(p - 1 + N) % N]++;
                }

                for (auto p: new_pos)
                    pos.push_back(p);

                K--;
            }

            long ans = 0LL;
            for (int i = 0; i < N; i++)
                ans += A[i];

            ans += 2LL * N * K;
            cout << ans << "\n";
        }
    }
}
