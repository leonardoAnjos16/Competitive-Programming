#include <bits/stdc++.h>

using namespace std;

#define long long long int

map<string, string> tree;
vector<vector<string>> cycles;
map<string, int> vis;
map<string, int> memo;

void get_cycle(string name) {
    vector<string> cycle;

    cycle.push_back(name);
    string curr = tree[name];

    while (curr != name) {
        cycle.push_back(curr);
        curr = tree[curr];
    }

    cycles.push_back(cycle);
}

void get_cycles(string name) {
    if (!tree.count(name) || vis[name] == 2) return;

    if (vis[name] == 1) get_cycle(name);
    else {
        vis[name] = 1;
        get_cycles(tree[name]);
        vis[name] = 2;
    }
}

int count(string name) {
    if (!tree.count(name)) return 0;
    if (memo.count(name)) return memo[name];
    return memo[name] = count(tree[name]) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--) {
        string family, name, son, of, father;
        cin >> family >> name >> son >> of >> father;
        tree[name + family] = father + family;
    }

    for (auto [child, father]: tree)
        if (!vis[child]) get_cycles(child);

    for (auto cycle: cycles)
        for (auto name: cycle)
            memo[name] = cycle.size();

    int ans = 0;
    for (auto [child, father]: tree)
        ans = max(ans, count(child));

    cout << ans << "\n";
}