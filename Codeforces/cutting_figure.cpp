#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, m, idx = 0;
vector<string> sheet;
vector<vector<int>> in, low;

bool articulation_point(int i, int j, int pi = -1, int pj = -1) {
    in[i][j] = low[i][j] = idx++;

    int children = 0;
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if ((k || l) && (!k || !l)) {
                int ni = i + k;
                int nj = j + l;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && sheet[ni][nj] == '#') {
                    if (~in[ni][nj] && (ni != pi || nj != pj)) low[i][j] = min(low[i][j], in[ni][nj]);
                    else if (in[ni][nj] == -1) {
                        children++;
                        if (articulation_point(ni, nj, i, j))
                            return true;

                        if (pi != -1 && low[ni][nj] >= in[i][j])
                            return true;
                            
                        low[i][j] = min(low[i][j], low[ni][nj]);
                    }
                }
            }

    if (pi == -1 && children > 1)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    sheet.resize(n);
    for (int i = 0; i < n; i++)
        cin >> sheet[i];

    in.assign(n, vector<int>(m, -1));
    low.assign(n, vector<int>(m));

    int r, c, cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sheet[i][j] == '#')
                r = i, c = j, cnt++;

    if (cnt <= 2) cout << "-1\n";
    else if (articulation_point(r, c)) cout << "1\n";
    else cout << "2\n";
}