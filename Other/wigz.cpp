#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int N, M, K;
vector<int> srow, scol;
vector<vector<int>> A;

int sum(int i = 0, int rows = 0) {
    if (rows > K) return -INF;
    if (i >= N) {
        vector<int> sums;
        for (int j = 0; j < M; j++)
            sums.push_back(scol[j]);

        sort(sums.rbegin(), sums.rend());

        int sum = 0;
        for (int j = 0; j < K - rows && j < M; j++)
            sum += sums[j];

        return sum;
    }

    int ans = sum(i + 1, rows);
    for (int j = 0; j < M; j++)
        scol[j] -= A[i][j];

    ans = max(ans, sum(i + 1, rows + 1) + srow[i]);
    for (int j = 0; j < M; j++)
        scol[j] += A[i][j];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("wigz.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        cin >> N >> M >> K;

        srow.assign(min(N, M), 0);
        scol.assign(max(N, M), 0);
        A.assign(min(N, M), vector<int>(max(N, M)));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (N <= M) {
                    cin >> A[i][j];
                    srow[i] += A[i][j];
                    scol[j] += A[i][j];
                } else {
                    cin >> A[j][i];
                    srow[j] += A[j][i];
                    scol[i] += A[j][i];
                }
            }

        if (N > M) swap(N, M);

        int ans = sum();
        cout << ans << "\n";
    }
}