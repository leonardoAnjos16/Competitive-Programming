#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<vi> adj, revAdj;
vi vis;

stack<int> bfs(int source) {
  queue<int> q;
  q.push(source);

  stack<int> leafs;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    if(vis[cur]) continue;
    vis[cur] = true;

    if(revAdj[cur].size() == 0) leafs.push(cur);

    for(auto next: revAdj[cur]) {
      q.push(next);
    }
  }
  return leafs;
}

int dfs(int cur) {
  vis[cur] = true;
  for(auto next: adj[cur]) {
    if(vis[next]) continue;
    return dfs(next) + 1;
  }

  return 1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  
  adj.resize(n);
  revAdj.resize(n);
  vis.resize(n);

  int parent;
  for(int i = 1; i < n; ++i) {
    cin >> parent;
    --parent;
    adj[i].PB(parent);
    revAdj[parent].PB(i);
  }

  auto leafs = bfs(0);
  priority_queue<int, vi> pq;

  vis.assign(n, 0);

  while(!leafs.empty()) {
    int cur = leafs.top(); leafs.pop();
    int dist = dfs(cur);
    pq.push(dist);
  }

  int ans = 0;
  while(k-- && !pq.empty()) {
    ans += pq.top(); pq.pop();
  }
  cout << ans << endl;

  return 0;
}
