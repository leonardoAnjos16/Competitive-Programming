#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<vector<bool>>> box(n, vector<vector<bool>>(m, vector<bool>(h, false)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int A; cin >> A;
            for (int k = 0; k < A; k++)
                box[i][j][k] = true;
        }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            int ans = 0;
            for (int k = 0; k < n; k++)
                ans += box[k][j][i];

            if (j) cout << " ";
            cout << ans;
        }

        cout << "\n";
    }
}