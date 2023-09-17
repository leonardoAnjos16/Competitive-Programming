#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> C[i][j];

    vector<vector<int>> dist = C;
    vector<vector<int>> cnt(N, vector<int>(N, 1));

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] == dist[i][j]) cnt[i][j]++;
                else if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    cnt[i][j] = 1;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }

    int ans = 0;
    bool coherent = true;

    for (int i = 0; i < N && coherent; i++)
        for (int j = 0; j < N && coherent; j++) {
            if (dist[i][j] < C[i][j]) coherent = false;
            else ans += (cnt[i][j] > 3);
        }

    if (!coherent) cout << "-1\n";
    else {
        assert(!(ans & 1));
        ans /= 2;

        cout << ans << "\n";
    }
}