#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M, A, B;
        cin >> N >> M >> A >> B;

        cout << "Case #" << t << ": ";
        if (A < N + M - 1 || B < N + M - 1) cout << "Impossible\n";
        else {
            vector<vector<int>> ans(N, vector<int>(M, 1));
            ans[0][0] = A - N - M + 2; ans[0][M - 1] = B - N - M + 2;

            cout << "Possible\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (j) cout << " ";
                    cout << ans[i][j];
                }

                cout << "\n";
            }
        }
    }
}