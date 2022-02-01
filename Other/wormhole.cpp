#include <bits/stdc++.h>

using namespace std;

int p;
vector<vector<long double>> g;
vector<vector<long double>> dists;

long double dist(int x1, int y1, int z1, int x2, int y2, int z2) {
    long double dx = x2 - x1, dy = y2 - y1, dz = z2 - z1;
    return sqrtl(dx * dx + dy * dy + dz * dz);
}

void get_dists() {
    dists = g;
    for (int k = 0; k < p; k++)
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (dists[i][k] + dists[k][j] < dists[i][j])
                    dists[i][j] = dists[i][k] + dists[k][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> p;

        map<string, int> ids;
        vector<tuple<int, int, int>> coords(p);

        for (int i = 0; i < p; i++) {
            string name; int x, y, z;
            cin >> name >> x >> y >> z;

            ids[name] = i;
            coords[i] = make_tuple(x, y, z);
        }

        g.assign(p, vector<long double>(p, 0.0L));
        for (int i = 0; i < p; i++)
            for (int j = i + 1; j < p; j++) {
                auto [x1, y1, z1] = coords[i];
                auto [x2, y2, z2] = coords[j];
                g[i][j] = g[j][i] = dist(x1, y1, z1, x2, y2, z2);
            }

        int w; cin >> w;
        while (w--) {
            string entrance, exit;
            cin >> entrance >> exit;
            g[ids[entrance]][ids[exit]] = 0.0L;
        }

        get_dists();
        cout << "Case " << t << ":\n";

        int q; cin >> q;
        while (q--) {
            string p1, p2;
            cin >> p1 >> p2;

            cout << "The distance from " << p1 << " to " << p2 << " is ";

            long long int ans = dists[ids[p1]][ids[p2]] + .5;
            cout << ans << " parsecs.\n";
        }
    }
}