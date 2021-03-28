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

const int MAX = 25;

int w, h;
string c[MAX];
vector<pii> V;
int d[MAX][MAX][MAX];

int memo[MAX][1 << 15];

bool get_dists() {
    for (int i = 0; i < size(V); i++) {
        d[i][V[i].fst][V[i].snd] = 0;

        queue<pii> aux;
        aux.push(V[i]);

        vector<bitset<MAX>> vis(h, bitset<MAX>());
        vis[V[i].fst][V[i].snd] = true;

        while (!aux.empty()) {
            pii v = aux.front(); aux.pop();
            int dist = d[i][v.fst][v.snd];

            pii u = { v.fst - 1, v.snd };
            if (u.fst >= 0 && c[u.fst][u.snd] != 'x' && !vis[u.fst][u.snd]) {
                aux.push(u);
                vis[u.fst][u.snd] = true;
                d[i][u.fst][u.snd] = dist + 1;
            }

            u = { v.fst + 1, v.snd };
            if (u.fst < h && c[u.fst][u.snd] != 'x' && !vis[u.fst][u.snd]) {
                aux.push(u);
                vis[u.fst][u.snd] = true;
                d[i][u.fst][u.snd] = dist + 1;
            }

            u = { v.fst, v.snd - 1 };
            if (u.snd >= 0 && c[u.fst][u.snd] != 'x' && !vis[u.fst][u.snd]) {
                aux.push(u);
                vis[u.fst][u.snd] = true;
                d[i][u.fst][u.snd] = dist + 1;
            }

            u = { v.fst, v.snd + 1 };
            if (u.snd < w && c[u.fst][u.snd] != 'x' && !vis[u.fst][u.snd]) {
                aux.push(u);
                vis[u.fst][u.snd] = true;
                d[i][u.fst][u.snd] = dist + 1;
            }
        }
    }

    for (int i = 1; i < size(V); i++)
        if (d[0][V[i].fst][V[i].snd] == -1)
            return false;

    return true;
}

int moves(int i = 0, int used = 1) {
    int n = size(V);
    if (used + 1 == (1 << n)) return 0;

    int &ans = memo[i][used];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int j = 0; j < n; j++)
        if (!(used & (1 << j)))
            ans = min(ans, d[i][V[j].fst][V[j].snd] + moves(j, used | (1 << j)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> w >> h, w || h) {
        vector<pii> aux;
        for (int i = 0; i < h; i++) {
            cin >> c[i];
            for (int j = 0; j < w; j++) {
                if (c[i][j] == 'o') V.pb({ i, j });
                else if (c[i][j] == '*') aux.pb({ i, j });
            }
        }

        for (auto p: aux) V.pb(p);
        memset(d, -1, sizeof d);

        bool possible = get_dists();
        if (!possible) cout << "-1\n";
        else {
            memset(memo, -1, sizeof memo);

            int ans = moves();
            cout << ans << "\n";
        }

        V.clear();
    }
}