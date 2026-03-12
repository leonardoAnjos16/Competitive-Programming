#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ll> iii;

const ll flow_inf = 1e18;
int n_stations, n_refinaria, n_edges;

vector<ll> stations;
vector<ll> refinaria;

struct FlowEdge {
    int v, u;
    int cost;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap, int cost) : v(v), u(u), cap(cap), cost(cost) {}
};

struct Dinic {
    int s, t;
    int n, m = 0;
    int limite_peso;

    queue<int> q;
    vector<int> level, ptr;
    vector<FlowEdge> edges;
    vector<vector<int> > adj;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void print(){
        for(int i = 0; i < edges.size(); i++){
            cout << edges[i].u << ' ' << edges[i].v << ' ' << edges[i].cap << ' ' << edges[i].flow << ' ' << edges[i].cost << '\n';
        }
    }

    void add_edge(int v, int u, ll cap, int cost) {
        edges.push_back(FlowEdge(v, u, cap, cost));
        edges.push_back(FlowEdge(u, v, 0, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int id : adj[v]) {
                //cout << v << ' ' << id << ' ' << edges[id].cost << '\n';
                // if(edges[id].cost > limite_peso) 
                //     continue;
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;

            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }

    void add(int max_w, int src, int snk, vector<iii> &edges_main){
        m = 0;
        adj.clear();
        edges.clear();
        
        adj.resize(n);

        for(int i = 1; i <= n_refinaria; i++){
            add_edge(src, i, refinaria[i], 0);
            add_edge(i, n_refinaria + i, refinaria[i], 0);
        }

        for(int i = 1; i <= n_stations; i++){
            add_edge(2*n_refinaria + i, 2*n_refinaria + n_stations + i, stations[i], 0);
            add_edge(2*n_refinaria + n_stations + i, snk, stations[i], 0);
        }

        for(int i = 0; i < n_edges; i++){
            int u = edges_main[i].first.first;
            int v = edges_main[i].first.second;
            int cost = edges_main[i].second;

            if(edges_main[i].second <= max_w) 
                add_edge(u + n_refinaria, 2*n_refinaria + v, flow_inf, cost);
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_stations >> n_refinaria >> n_edges;
    
    ll sum = 0;
    vector<iii> edges_main;

    refinaria.resize(n_refinaria + 1);
    stations.resize(n_stations + 1);

    for(int i = 1; i <= n_stations; i++) {
        cin >> stations[i];
        sum += stations[i];
    }

    for(int i = 1; i <= n_refinaria; i++) cin >> refinaria[i];

    int src = 0, snk = 2*n_stations + 2*n_refinaria + 1;

    Dinic gabmei(snk+1, src, snk);

    for(int i = 1; i <= n_refinaria; i++){
        gabmei.add_edge(src, i, refinaria[i], 0);
        gabmei.add_edge(i, n_refinaria + i, refinaria[i], 0);
    }

    for(int i = 1; i <= n_stations; i++){
        gabmei.add_edge(2*n_refinaria + i, 2*n_refinaria + n_stations + i, stations[i], 0);
        gabmei.add_edge(2*n_refinaria + n_stations + i, snk, stations[i], 0);
    }

    int max_weight = 0;

    for(int i = 0; i < n_edges; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        swap(u, v);
        edges_main.push_back(make_pair(make_pair(u, v), cost));
        gabmei.add_edge(u + n_refinaria, 2*n_refinaria + v, flow_inf, cost);

        max_weight = max(max_weight, cost);
    }

    gabmei.limite_peso = max_weight;

    int max_flow = gabmei.flow();

    if(max_flow < sum){
        cout << "-1\n";
        return 0;
    }

    int l = 0, r = max_weight;

    while(l < r){
        int mid = (l + r) >> 1;
        gabmei.limite_peso = mid;

        gabmei.add(mid, src, snk, edges_main);

        int flow_atual = gabmei.flow();

        if(flow_atual == max_flow) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';

    return 0;
}