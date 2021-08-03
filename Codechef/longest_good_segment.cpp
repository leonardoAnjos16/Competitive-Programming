#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K; long S;
        cin >> N >> K >> S;

        vector<long> ps(N + 1, 0LL);
        for (int i = 1; i <= N; i++) {
            cin >> ps[i];
            ps[i] += ps[i - 1];
        }

        vector<int> right(N + 2);
        for (int i = 1; i <= N; i++)
            right[i] = upper_bound(ps.begin(), ps.end(), ps[i - 1] + S) - ps.begin();

        right[N + 1] = N + 1;

        vector<vector<int>> nxt(N + 2, vector<int>(LOG));
        for (int i = 1; i <= N + 1; i++)
            nxt[i][0] = right[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 1; j <= N + 1; j++)
                nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];

        int ans = 1;
        for (int i = 1; i <= N; i++) {
            int r = i;
            for (int j = 0; j < LOG; j++)
                if (K & (1 << j))
                    r = nxt[r][j];

            int cnt = r - i;
            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }
}