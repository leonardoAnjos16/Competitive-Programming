#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        vector<string> C(N);
        for (int i = 0; i < N; i++)
            cin >> C[i];

        vector<pair<int, int>> rows(N, make_pair(0, 0));
        vector<pair<int, int>> cols(N, make_pair(0, 0));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (C[i][j] == 'X') {
                    rows[i].first++;
                    cols[j].first++;
                } else if (C[i][j] == 'O') {
                    rows[i].second++;
                    cols[j].second++;
                }
            }

        int mn = INT_MAX, cnt = -1;
        for (int i = 0; i < N; i++) {
            if (!rows[i].second) {
                if (N - rows[i].first == mn) cnt++;
                else if (N - rows[i].first < mn) {
                    mn = N - rows[i].first;
                    cnt = 1;
                }
            }

            if (!cols[i].second) {
                if (N - cols[i].first == mn) cnt++;
                else if (N - cols[i].first < mn) {
                    mn = N - cols[i].first;
                    cnt = 1;
                }
            }
        }

        if (mn == 1) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (N - rows[i].first == 1 && N - cols[j].first == 1 && C[i][j] == '.')
                        cnt--;
        }

        cout << "Case #" << t << ": ";
        if (cnt == -1) cout << "Impossible\n";
        else cout << mn << " " << cnt << "\n";
    }
}