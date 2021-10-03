#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<string> field;
vector<vector<int>> dists;

void get_dists() {
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    vis[0][0] = true;

    dists.assign(N, vector<int>(N, -1));
    dists[0][0] = 0;

    deque<pair<int, int>> aux;
    aux.emplace_back(0, 0);

    while (!aux.empty()) {
        auto [vi, vj] = aux.front();
        aux.pop_front();

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ((i || j) && !(i && j)) {
                    int ui = vi + i;
                    int uj = vj + j;

                    if (ui >= 0 && ui < N && uj >= 0 && uj < N && !vis[ui][uj]) {
                        vis[ui][uj] = true;
                        dists[ui][uj] = dists[vi][vj] + (field[ui][uj] == '0');
                        
                        if (field[ui][uj] == '1') aux.emplace_front(ui, uj);
                        else aux.emplace_back(ui, uj);
                    }
                }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    field.resize(N);
    for (int i = 0; i < N; i++)
        cin >> field[i];

    get_dists();

    int ans = dists[N - 1][N - 1];
    cout << ans << "\n";
}