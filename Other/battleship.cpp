#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    bool vis[MAX][MAX] = {0};

    int sum = 0;
    while (N--) {
        int D, L, R, C;
        cin >> D >> L >> R >> C;

        if (!D) {
            for (int i = C - 1; i < C + L - 1 && i < MAX; i++)
                vis[R - 1][i] = true;
        } else {
            for (int i = R - 1; i < R + L - 1 && i < MAX; i++)
                vis[i][C - 1] = true;
        }

        sum += L;
    }

    int cnt = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cnt += vis[i][j];

    cout << (sum == cnt ? 'Y' : 'N') << "\n";
}