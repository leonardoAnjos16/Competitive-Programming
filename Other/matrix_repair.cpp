#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    vector<int> R(N);
    for (int i = 0; i < N; i++)
        cin >> R[i];

    vector<int> C(N);
    for (int i = 0; i < N; i++)
        cin >> C[i];

    vector<vector<int>> cntr(2, vector<int>(N, 0));
    vector<vector<int>> cntc(2, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] != -1) {
                cntr[A[i][j]][i]++;
                cntc[A[i][j]][j]++;
            }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        bool odd = R[i] ^ (cntr[1][i] & 1);
        int unknown = N - cntr[0][i] - cntr[1][i];

        if (unknown == 1)
            for (int j = 0; j < N; j++)
                if (A[i][j] == -1 && !vis[i][j]) {
                    A[i][j] = odd;
                    cntr[odd][i]++;
                    cntc[odd][j]++;

                    q.emplace(i, j);
                    vis[i][j] = true;
                }

        odd = C[i] ^ (cntc[1][i] & 1);
        unknown = N - cntc[0][i] - cntc[1][i];

        if (unknown == 1)
            for (int j = 0; j < N; j++)
                if (A[j][i] == -1 && !vis[j][i]) {
                    A[j][i] = odd;
                    cntr[odd][j]++;
                    cntc[odd][i]++;

                    q.emplace(j, i);
                    vis[j][i] = true;
                }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        bool odd = R[i] ^ (cntr[1][i] & 1);
        int unknown = N - cntr[0][i] - cntr[1][i];

        if (unknown == 1)
            for (int k = 0; k < N; k++)
                if (A[i][k] == -1 && !vis[i][k]) {
                    A[i][k] = odd;
                    cntr[odd][i]++;
                    cntc[odd][k]++;

                    q.emplace(i, k);
                    vis[i][k] = true;
                }

        odd = C[j] ^ (cntc[1][j] & 1);
        unknown = N - cntc[0][j] - cntc[1][j];

        if (unknown == 1)
            for (int k = 0; k < N; k++)
                if (A[k][j] == -1 && !vis[k][j]) {
                    A[k][j] = odd;
                    cntr[odd][k]++;
                    cntc[odd][j]++;

                    q.emplace(k, j);
                    vis[k][j] = true;
                }
    }

    bool possible = true;
    for (int i = 0; i < N && possible; i++)
        for (int j = 0; j < N && possible; j++)
            if (A[i][j] == -1) possible = false;

    if (!possible) cout << "-1\n";
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j) cout << " ";
                cout << A[i][j];
            }

            cout << "\n";
        }
    }
}