#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 505;

vector<vector<int>> g;
vector<int> cycle;

int shortest_cycle(int v) {
    bitset<MAX> vis;
    vis[v] = true;

    queue<int> aux;
    aux.push(v);

    vector<int> p(g.size());
    p[v] = v;

    while (!aux.empty()) {
        int u = aux.front(); aux.pop();
        for (auto w: g[u]) {
            if (vis[w] && w == v) {
                cycle.clear();

                cycle.push_back(u);
                while (p[u] != u) {
                    cycle.push_back(p[u]);
                    u = p[u];
                }

                reverse(cycle.begin(), cycle.end());
                return (int) cycle.size();
            } else if (!vis[w]) {
                p[w] = u;
                aux.push(w);
                vis[w] = true;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<string, int> to_id;
    vector<string> to_name(n);

    for (int i = 0; i < n; i++) {
        cin >> to_name[i];
        to_id[to_name[i]] = i;
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        string name; int k;
        cin >> name >> k;
        cin.ignore();

        int id = to_id[name];
        while (k--) {
            string line; getline(cin, line);
            stringstream ss(line);

            string file; ss >> file;
            while (ss >> file) {
                if (file.back() == ',')
                    file.pop_back();

                g[id].push_back(to_id[file]);
            }
        }
    }

    /* for (int i = 0; i < n; i++) {
        for (auto v: g[i]) cout << v << " ";
        cout << "\n";
    } */

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int curr = shortest_cycle(i);
        if (curr && (ans.empty() || cycle.size() < ans.size()))
            ans = cycle;
    }

    if (ans.empty()) cout << "SHIP IT\n";
    else {
        for (int i = 0; i < (int) ans.size(); i++) {
            if (i) cout << " ";
            cout << to_name[ans[i]];
        }

        cout << "\n";
    }
}