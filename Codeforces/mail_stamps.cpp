#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 1e9 + 5;

map<int, vector<int>> g;
map<int, bool> vis;
vector<int> ans;

void dfs(int v) {
    if (vis[v]) return;

    vis[v] = true;
    ans.push_back(v);

    for (auto u: g[v]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--) {
        int A, B;
        cin >> A >> B;

        g[A].push_back(B);
        g[B].push_back(A);
        vis[A] = vis[B] = false;
    }

    for (auto p: g) {
        if (size(p.snd) == 1) {
            dfs(p.fst);
            break;
        }
    }

    for (auto v: ans)
        cout << v << " ";

    cout << "\n";
}