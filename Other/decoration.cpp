#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> vis, dist;
vector<vector<int>> cycles;

vector<pair<int, long>> operator *(vector<pair<int, long>> &a, vector<pair<int, long>> &b) {
    int n = a.size();
    vector<pair<int, long>> ans(n);

    for (int i = 0; i < n; i++)
        ans[i] = make_pair(a[b[i].first].first, b[i].second + a[b[i].first].second);

    return ans;
}

vector<pair<int, long>> exp(vector<pair<int, long>> &v, int k) {
    if (k == 1) return v;

    vector<pair<int, long>> ans = exp(v, k >> 1);
    ans = ans * ans;

    if (k & 1)
        ans = ans * v;
    
    return ans;
}

void get_cycle(vector<pair<int, long>> &nxt, int v) {
    vector<int> cycle;
    cycle.push_back(v);

    int u = nxt[v].first;
    while (u != v) {
        cycle.push_back(u);
        u = nxt[u].first;
    }

    cycles.push_back(cycle);
}

void get_cycles(vector<pair<int, long>> &nxt, int v) {
    if (vis[v] == 1) get_cycle(nxt, v);
    else if (!vis[v]) {
        vis[v]++;
        get_cycles(nxt, nxt[v].first);
        vis[v]++;
    }
}

void get_dist(vector<pair<int, long>> &nxt, int v) {
    if (dist[v]) return;

    get_dist(nxt, nxt[v].first);
    dist[v] = dist[nxt[v].first] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> divs(N, 0);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j]++;

    vector<pair<int, long>> nxt(N);
    for (int i = 0; i < N; i++)
        nxt[i] = make_pair((i + divs[i]) % N, i);

    vector<pair<int, long>> to = exp(nxt, K);

    vis.assign(N, 0);
    for (int i = 0; i < N; i++)
        if (!vis[i]) get_cycles(nxt, i);

    dist.assign(N, 0);
    for (auto cycle: cycles)
        for (auto v: cycle)
            dist[v] = cycle.size();

    for (int i = 0; i < N; i++)
        if (!dist[i]) get_dist(nxt, i);

    int start = -1;
    long cost = LLONG_MAX;

    for (int i = 0; i < N; i++)
        if (dist[i] >= K && to[i].second < cost) {
            start = i;
            cost = to[i].second;
        }

    if (start == -1) cout << "-1\n";
    else {
        int ans = start;
        for (int i = 0; i < K; i++) {
            if (i) cout << " ";
            cout << ans;
            ans = nxt[ans].first;
        }

        cout << "\n";
    }
}