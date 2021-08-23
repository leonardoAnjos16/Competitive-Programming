#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int R, C, M, N;
vector<bitset<MAX>> water;
vector<bitset<MAX>> vis;
vector<vector<int>> cnt;

void count(int i = 0, int j = 0) {
    vis[i][j] = true;
    if (!(M + N)) return;

    set<int> reachable;
    for (int k = i - M; k <= i + M; k += M + M) {
        for (int l = j - N; l <= j + N; l += N + N) {
            if (k >= 0 && k < R && l >= 0 && l < C && !water[k][l]) {
                reachable.insert(k * R + l);
                if (!vis[k][l])
                    count(k, l);
            }

            if (!N) break;
        }

        if (!M) break;
    }

    for (int k = i - N; k <= i + N; k += N + N) {
        for (int l = j - M; l <= j + M; l += M + M) {
            if (k >= 0 && k < R && l >= 0 && l < C && !water[k][l]) {
                reachable.insert(k * R + l);
                if (!vis[k][l])
                    count(k, l);
            }

            if (!M) break;
        }

        if (!N) break;
    }

    cnt[i][j] = reachable.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C >> M >> N;
        int W; cin >> W;

        water.assign(R, bitset<MAX>());
        while (W--) {
            int x, y;
            cin >> x >> y;
            water[x][y] = true;
        }

        vis.assign(R, bitset<MAX>());
        cnt.assign(R, vector<int>(C, 0));

        count();

        int even = 0, odd = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (cnt[i][j] & 1) odd++;
                else if (vis[i][j]) even++;
            }

        cout << "Case " << t << ": " << even << " " << odd << "\n";
    }
}