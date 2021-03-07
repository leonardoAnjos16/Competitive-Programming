#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

map<pii, int> dist;

void distances(int i, int j) {
    queue<pii> aux;
    aux.push({ i, j });

    set<pii> vis;
    vis.insert({ i, j });

    dist[{ i, j }] = 0;
    while (!aux.empty()) {
        pii top = aux.front(); aux.pop();
        for (int k = -2; k <= 2; k++)
            for (int l = -2; l <= 2; l++)
                if (k && l && abs(k) != abs(l)) {
                    int row = top.fst + k;
                    int col = top.snd + l;

                    if (!vis.count({ row, col }) && row >= 0 && row < 8 && col >= 0 && col < 8) {
                        aux.push({ row, col });
                        vis.insert({ row, col });
                        dist[{ row, col }] = dist[top] + 1;
                    }
                }
    }
}

pii to_pair(string cell) {
    return { cell[1] - '1', cell[0] - 'a' };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string u, v;
        cin >> u >> v;

        pii origin = to_pair(u);
        pii goal = to_pair(v);

        distances(origin.fst, origin.snd);

        int ans = dist[goal];
        cout << ans << "\n";

        dist.clear();
    }
}