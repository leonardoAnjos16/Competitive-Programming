#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        if (N == 2) cout << "-1 -1\n-1 -1\n";
        else {
            vector<vector<int>> ans(N, vector<int>(N, 1));
            for (int i = 0; i < N; i++)
                ans[i][i] = -1;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j) cout << " ";
                    cout << ans[i][j];
                }

                cout << "\n";
            }
        }
    }
}