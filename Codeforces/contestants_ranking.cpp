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

const int MAX = 305;

map<string, vector<string>> g;
map<string, int> ranks;

void get_ranks() {
    set<string> vis;
    queue<string> aux;

    aux.push("Ahmad");
    ranks["Ahmad"] = 0;
    vis.insert("Ahmad");

    while (!aux.empty()) {
        string v = aux.front(); aux.pop();
        for (auto u: g[v]) {
            if (!vis.count(u)) {
                aux.push(u);
                vis.insert(u);
                ranks[u] = ranks[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        while (N--) {
            string team[3];
            for (int i = 0; i < 3; i++)
                cin >> team[i];

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (i != j)
                        g[team[i]].push_back(team[j]);
        }

        get_ranks();

        map<int, set<string>> ans;
        for (auto p: g) {
            int idx = ranks.count(p.fst) ? ranks[p.fst] : -1;
            ans[idx].insert(p.fst);
        }

        cout << size(g) << "\n";
        for (auto p: ans)
            if (p.fst != -1)
                for (auto s: p.snd)
                    cout << s << " " << p.fst << "\n";

        for (auto s: ans[-1])
            cout << s << " undefined\n";

        g.clear();
        ranks.clear();
    }
}