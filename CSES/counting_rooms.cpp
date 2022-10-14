#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<string> building;
vector<vector<bool>> vis;
 
void traverse(int i, int j) {
    vis[i][j] = true;
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++) 
            if ((di || dj) && !(di && dj)) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && building[ni][nj] == '.' && !vis[ni][nj])
                    traverse(ni, nj);
            }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    building.resize(n);
    for (int i = 0; i < n; i++)
        cin >> building[i];
 
    vis.assign(n, vector<bool>(m, false));
 
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (building[i][j] == '.' && !vis[i][j]) {
                ans++;
                traverse(i, j);
            }
 
    cout << ans << "\n";
}