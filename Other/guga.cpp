#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> component;

void get_component(int v, int id) {
    if (component[v] != -1) return;

    component[v] = id;
    for (int u: g[v])
        get_component(u, id);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M; cin >> M;

    vector<string> adjectives;
    vector<pair<string, string>> synonyms;

    for (int i = 0; i < M; i++) {
        string A, B;
        cin >> A >> B;

        adjectives.push_back(A);
        adjectives.push_back(B);
        synonyms.emplace_back(A, B);
    }

    sort(adjectives.begin(), adjectives.end());
    adjectives.erase(unique(adjectives.begin(), adjectives.end()), adjectives.end());

    int cnt = adjectives.size();
    g.assign(cnt, vector<int>());

    for (auto [A, B]: synonyms) {
        int u = lower_bound(adjectives.begin(), adjectives.end(), A) - adjectives.begin();
        int v = lower_bound(adjectives.begin(), adjectives.end(), B) - adjectives.begin();

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int components = 0;
    component.assign(cnt, -1);

    for (int i = 0; i < cnt; i++)
        if (component[i] == -1)
            get_component(i, components++);

    vector<int> component_size(components, 0);
    for (int i = 0; i < cnt; i++)
        component_size[component[i]]++;

    int Q; cin >> Q;
    while (Q--) {
        string S; cin >> S;

        int v = lower_bound(adjectives.begin(), adjectives.end(), S) - adjectives.begin();
        if (component_size[component[v]] & 1) cout << "N\n";
        else cout << "S\n";
    }
}