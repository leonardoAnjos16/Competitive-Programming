#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ldouble> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];

    vector<ldouble> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    ldouble prob = 1.0L;
    vector<ldouble> ans(N, 0.0L);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            ans[j] += prob * (1.0L - P[j]);

            prob *= P[j];
            P[j] *= (1.0L - T[j]);
        }

    cout << setprecision(8) << fixed;
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
}