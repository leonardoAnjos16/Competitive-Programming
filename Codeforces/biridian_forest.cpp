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

const int MAX = 1e3 + 5;

string breeders_map[MAX];
int dists[MAX][MAX], r, c;

void get_dists(int i, int j) {
    vector<bitset<MAX>> vis(r, bitset<MAX>());
    vis[i][j] = true;

    queue<pii> aux;
    aux.emplace(i, j);

    for (int k = 0; k < r; k++)
        for (int l = 0; l < c; l++)
            dists[k][l] = INT_MAX;

    dists[i][j] = 0;
    while (!aux.empty()) {
        pii v = aux.front(); aux.pop();
        for (int k = -1; k <= 1; k++)
            for (int l = -1; l <= 1; l++)
                if ((k || l) && !(k && l)) {
                    pii u = { v.fst + k, v.snd + l };
                    if (u.fst >= 0 && u.fst < r && u.snd >= 0 && u.snd < c && breeders_map[u.fst][u.snd] != 'T')
                        if (!vis[u.fst][u.snd]) {
                            aux.push(u);
                            vis[u.fst][u.snd] = true;
                            dists[u.fst][u.snd] = dists[v.fst][v.snd] + 1;
                        }
                }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    pii start, exit;
    vector<pii> breeders;

    for (int i = 0; i < r; i++) {
        cin >> breeders_map[i];
        for (int j = 0; j < c; j++) {
            if (breeders_map[i][j] == 'S') start = { i, j };
            else if (breeders_map[i][j] == 'E') exit = { i, j };
            else if (breeders_map[i][j] != 'T') breeders.pb({ i, j });
        }
    }

    get_dists(exit.fst, exit.snd);

    int ans = 0;
    for (auto group: breeders)
        if (dists[group.fst][group.snd] <= dists[start.fst][start.snd])
            ans += breeders_map[group.fst][group.snd] - '0';

    cout << ans << "\n";
}