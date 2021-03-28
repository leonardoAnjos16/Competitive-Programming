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

const int MAX = 30;
const int INF = 1e9;

int w, h;
string m[MAX];
int d[MAX][MAX];

void djikstra(int i, int j) {
    vector<bitset<MAX>> vis(h, bitset<MAX>());
    for (int k = 0; k < h; k++)
        for (int l = 0; l < w; l++)
            d[k][l] = INF;

    pq<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> heap;
    heap.push({ 0, { i, j } });

    d[i][j] = 0;
    for (int k = 0; k < h * w; k++) {
        pii v;
        do {
            if (heap.empty()) return;
            v = heap.top().snd; heap.pop();
        } while (vis[v.fst][v.snd]);

        vis[v.fst][v.snd] = true;

        pii u = v; u.fst--;
        if (u.fst >= 0 && m[u.fst][u.snd] != 'X' && !vis[u.fst][u.snd]) {
            if (m[u.fst][u.snd] == 'D' && d[v.fst][v.snd] < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd];
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            } else if (d[v.fst][v.snd] + m[u.fst][u.snd] - '0' < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd] + m[u.fst][u.snd] - '0';
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            }
        }

        u = v; u.fst++;
        if (u.fst < h && m[u.fst][u.snd] != 'X' && !vis[u.fst][u.snd]) {
            if (m[u.fst][u.snd] == 'D' && d[v.fst][v.snd] < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd];
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            } else if (d[v.fst][v.snd] + m[u.fst][u.snd] - '0' < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd] + m[u.fst][u.snd] - '0';
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            }
        }

        u = v; u.snd--;
        if (u.snd >= 0 && m[u.fst][u.snd] != 'X' && !vis[u.fst][u.snd]) {
            if (m[u.fst][u.snd] == 'D' && d[v.fst][v.snd] < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd];
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            } else if (d[v.fst][v.snd] + m[u.fst][u.snd] - '0' < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd] + m[u.fst][u.snd] - '0';
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            }
        }

        u = v; u.snd++;
        if (u.snd < w && m[u.fst][u.snd] != 'X' && !vis[u.fst][u.snd]) {
            if (m[u.fst][u.snd] == 'D' && d[v.fst][v.snd] < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd];
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            } else if (d[v.fst][v.snd] + m[u.fst][u.snd] - '0' < d[u.fst][u.snd]) {
                d[u.fst][u.snd] = d[v.fst][v.snd] + m[u.fst][u.snd] - '0';
                heap.push({ d[u.fst][u.snd], { u.fst, u.snd } });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> w >> h, w || h) {
        int sx, sy, dx, dy;
        for (int i = 0; i < h; i++) {
            cin >> m[i];
            for (int j = 0; j < w; j++) {
                if (m[i][j] == 'S') sx = i, sy = j;
                else if (m[i][j] == 'D') dx = i, dy = j;
            }
        }

        djikstra(sx, sy);

        int ans = d[dx][dy];
        cout << ans << "\n";
    }
}