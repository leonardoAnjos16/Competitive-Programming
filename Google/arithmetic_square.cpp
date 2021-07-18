#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int G[3][3] = {0};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue;
                cin >> G[i][j];
            }

        int ans = 0;
        for (int i = 0; i < 3; i += 2) {
            if (G[i][1] - G[i][0] == G[i][2] - G[i][1]) ans++;
            if (G[1][i] - G[0][i] == G[2][i] - G[1][i]) ans++;
        }

        vector<pair<int, int>> aux;
        aux.push_back(make_pair(G[0][0], G[2][2]));
        aux.push_back(make_pair(G[0][1], G[2][1]));
        aux.push_back(make_pair(G[0][2], G[2][0]));
        aux.push_back(make_pair(G[1][0], G[1][2]));

        int mx = 0;
        for (int i = 0; i < 4; i++) {
            int diff = aux[i].second - aux[i].first, cnt = 0;
            if (!(diff & 1)) {
                int mid = aux[i].first + diff / 2;
                for (int j = 0; j < 4; j++)
                    if (mid - aux[j].first == aux[j].second - mid) cnt++;
            }

            mx = max(mx, cnt);
        }

        ans += mx;
        cout << "Case #" << t << ": " << ans << "\n";
    }
}