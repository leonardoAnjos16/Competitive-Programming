#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

vector<vector<int>> g;
vector<int> in, low;
bitset<MAX> ap;
int idx;

void get_ap(int v = 0, int p = -1) {
    in[v] = low[v] = idx++;

    int children = 0;
    for (auto u: g[v]) {
        if (~in[u] && u != p) low[v] = min(low[v], in[u]);
        else if (in[u] == -1) {
            children++;
            get_ap(u, v);

            if (low[u] >= in[v]) ap[v] = true;
            low[v] = min(low[v], low[u]);
        }
    }

    if (p == -1) ap[v] = children > 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num_case = 1;
    while (cin >> N, N) {
        if (num_case > 1) cout << "\n";

        map<string, int> pos;
        vector<string> cities(N);

        for (int i = 0; i < N; i++) {
            cin >> cities[i];
            pos[cities[i]] = i;
        }

        g.assign(N, vector<int>());

        int R; cin >> R;
        while (R--) {
            string u, v;
            cin >> u >> v;

            g[pos[u]].push_back(pos[v]);
            g[pos[v]].push_back(pos[u]);
        }

        in.assign(N, -1);
        low.resize(N);
        ap.reset();
        idx = 0;

        for (int i = 0; i < N; i++)
            if (in[i] == -1) get_ap(i);

        int ans = 0;
        vector<string> cameras;

        for (int i = 0; i < N; i++)
            if (ap[i]) {
                ans++;
                cameras.push_back(cities[i]);
            }

        sort(cameras.begin(), cameras.end());

        cout << "City map #" << num_case++ << ": " << ans << " camera(s) found\n";
        for (auto city: cameras) cout << city << "\n";
    }
}