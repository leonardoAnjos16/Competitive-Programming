#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int last_one = -1;
        vector<int> dists(N, -1);

        dists[0] = 0;
        for (int i = 0; i < N; i++) {
            if (A[i]) {
                dists[i] = 0;
                if (A[i] == 1)
                    last_one = i;
            } else if (~last_one) {
                int dist = i - last_one;
                dists[i] = dist;
            }
        }

        int last_two = -1;
        for (int i = N - 1; i >= 0; i--) {
            if (A[i] == 2) last_two = i;
            else if (!A[i] && ~last_two) {
                int dist = last_two - i;
                if (dists[i] == -1 || dist < dists[i])
                    dists[i] = dist;
            }
        }

        for (int i = 0; i < M; i++) {
            if (i) cout << " ";

            int B; cin >> B;
            cout << dists[B - 1];
        }

        cout << "\n";
    }
}