#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 405;
const int MAXQ = 1e5+5;
const ll INF = 1e18 + 5;

int n, r;
ll tmp[MAXN][MAXN];
ll dist[MAXN][MAXN];

void read(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i = 0; i < r; i++){
        ll t;
        int u, v;
        cin >> u >> v >> t;
        dist[u][v] = dist[v][u] =  min(dist[u][v], t);
    }
}

void copy(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            tmp[i][j] = dist[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;

    vector<pair<ll, int> > planets(n+5);
    for(int i = 1; i <= n; i++){
        cin >> planets[i].first;
        planets[i].second = i;
    }

    read();

    sort(planets.begin() + 1, planets.begin() + 1 + n);

    vector<pair<int, ii> > query_low[MAXN];
    vector<pair<int, ii> > query_high[MAXN];

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int u, v, k, t, cnt = 0;
        cin >> u >> v >> k >> t;

        if(t){  //Mais quentes
            for(int j = n; j > 0; j--){
                while(j > 1 && planets[j].first == planets[j-1].first) j--;
                if(++cnt >= k){
                    query_high[j].push_back(make_pair(i, make_pair(u, v)));
                    break;
                }
            }
            if(cnt < k) query_high[1].push_back(make_pair(i, make_pair(u, v)));
        }
        else{   //Mais frios
            for(int j = 1; j <= n; j++){
                while(j < n && planets[j].first == planets[j+1].first) j++;
                if(++cnt >= k){
                    query_low[j].push_back(make_pair(i, make_pair(u, v)));
                    break;
                }
            }
            if(cnt < k) query_low[n].push_back(make_pair(i, make_pair(u, v)));
        }
    }

    vector<ll> ans(MAXQ);

    copy();

    for(int k = 1; k <= n; k++){
        int id = planets[k].second;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                tmp[i][j] = tmp[j][i] = min(tmp[i][j], tmp[i][id] + tmp[id][j]);
            }
        }
        for(auto x: query_low[k]){
            ans[x.first] = tmp[x.second.first][x.second.second];
        }
    }

    copy();

    for(int k = n; k >= 1; k--){
        int id = planets[k].second;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                tmp[i][j] = tmp[j][i] = min(tmp[i][j], tmp[i][id] + tmp[id][j]);
            }
        }
        for(auto x: query_high[k]){
            ans[x.first] = tmp[x.second.first][x.second.second];
        }
    }

    for(int i = 1; i <= q; i++){
        if(ans[i] < INF) cout << ans[i] << '\n';
        else cout << "-1\n";
    }
}