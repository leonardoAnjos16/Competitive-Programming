#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> seq(N);
        for (int i = 0; i < N; i++)
            cin >> seq[i];

        vector<int> forward(N);
        vector<int> backward(N);

        forward[N - 1] = 1;
        backward[N - 1] = 1;

        for (int i = N - 2; i >= 0; i--) {
            if (seq[i] >= seq[i + 1]) forward[i] = 1;
            else forward[i] = forward[i + 1] + 1;

            if (seq[i] <= seq[i + 1]) backward[i] = 1;
            else backward[i] = backward[i + 1] + 1;
        }

        int hill = 0, dale = 0;
        for (int i = 0; i < N; i++) {
            int height = forward[i] - 1;
            height = min(height, backward[i + height] - 1);

            int depth = backward[i] - 1;
            depth = min(depth, forward[i + depth] - 1);

            hill = max(hill, height);
            dale = max(dale, depth);
        }

        cout << hill << " " << dale << "\n";
    }
}