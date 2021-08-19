#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, A, B, C, D, P, Q, Y;
        cin >> N >> A >> B >> C >> D >> P >> Q >> Y;

        vector<int> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];

        A--; B--; C--; D--;

        int ans = P * abs(x[A] - x[B]);
        if (P * abs(x[A] - x[C]) <= Y)
            ans = min(ans, Y + Q * abs(x[C] - x[D]) + P * abs(x[D] - x[B]));

        cout << ans << "\n";
    }
}