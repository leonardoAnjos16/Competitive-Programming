#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    int ans = 1;
    for (int i = 0; i < N; i++) {
        int idx = 0;
        while (idx < M) {
            int cnt = 1;
            while (idx + 1 < M && abs(a[i][idx + 1] - a[i][idx]) <= 1)
                idx++, cnt++;

            ans = max(ans, cnt);
            idx++;
        }
    }

    for (int i = 0; i < M; i++) {
        int idx = 0;
        while (idx < N) {
            int cnt = 1;
            while (idx + 1 < N && abs(a[idx + 1][i] - a[idx][i]) <= 1)
                idx++, cnt++;

            ans = max(ans, cnt);
            idx++;
        }
    }

    cout << ans << "\n";
}