#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C;
        cin >> R >> C;

        vector<vi> A(R + 1, vi(C + 1));
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                cin >> A[i][j];

        vector<vector<vi>> cnt(R + 2, vector<vi>(C + 2, vi(4, 0)));
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (A[i][j]) {    
                    cnt[i][j][0] = cnt[i][j - 1][0] + 1;
                    cnt[i][j][1] = cnt[i - 1][j][1] + 1;
                }

                if (A[i][C - j + 1]) cnt[i][C - j + 1][2] = cnt[i][C - j + 2][2] + 1;
                if (A[R - i + 1][j]) cnt[R - i + 1][j][3] = cnt[R - i + 2][j][3] + 1;
            }
        }

        long ans = 0LL;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                for (int k = 0; k < 4; k++) {
                    int aux = min(cnt[i][j][k], cnt[i][j][(k + 1) % 4] / 2);
                    ans += max(aux - 1, 0);

                    aux = min(cnt[i][j][(k + 1) % 4], cnt[i][j][k] / 2);
                    ans += max(aux - 1, 0);
                }
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}