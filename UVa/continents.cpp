#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;

int M, N;
char land;
vector<string> mp;
vector<bitset<MAX>> vis;

int size(int i, int j) {
    vis[i][j] = true;

    int ans = 1;
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if ((k || l) && (!k || !l)) {
                int ni = i + k;
                int nj = (j + l + N) % N;

                if (ni >= 0 && ni < M && mp[ni][nj] == land && !vis[ni][nj])
                    ans += size(ni, nj);
            }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> M >> N) {
        mp.resize(M);
        for (int i = 0; i < M; i++)
            cin >> mp[i];

        int X, Y;
        cin >> X >> Y;
        land = mp[X][Y];

        vis.assign(M, bitset<MAX>());
        size(X, Y);

        int ans = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (mp[i][j] == land && !vis[i][j])
                    ans = max(ans, size(i, j));

        cout << ans << "\n";
    }
}