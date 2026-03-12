#include "bits/stdc++.h"
using namespace std;

typedef long double ld;
typedef pair<ld, int> ldi;

const int MAXN = 105;
const int MAXK = 1030;
const ld INF = 1e18 + 5;

int n, k;
ld dist[MAXK][MAXN*MAXN];
vector<vector<pair<int, ld> > > adj;

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

ld euclidean_dist(pair<int, int> &a, pair<int, int> &b){
    ld x = a.first - b.first;
    ld y = a.second - b.second;

    return sqrt(x*x + y*y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(5) << fixed;

    cin >> n >> k;

    vector<pair<int, int> > edges(n);

    for(int i = 0; i < n; i++)
        cin >> edges[i].first >> edges[i].second;

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            dist[i][j] = INF;

    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
        for(int j = k; j < n; j++){
            dist[i][j] = euclidean_dist(edges[i], edges[j]);
        }
    }

    floyd();

    //Compute Steiner Trees
    vector<vector<ld> > minDist(1 << k, vector<ld> (n, INF));

    for(int i = 0; i < k; i++) minDist[1 << i][i] = 0;

    for(int mask = 0; mask < (1 << k); mask++){
        for(int i = 0; i < n; i++){
            for(int ss = mask; ss > 0; ss = (ss - 1) & mask){   //compute all possible subtrees being joined in rooted i
                minDist[mask][i] = min(minDist[mask][i], minDist[ss][i] + minDist[mask - ss][i]);
            }
            if(minDist[mask][i] < INF){
                for(int j = 0; j < n; j++){
                    minDist[mask][j] = min(minDist[mask][j], minDist[mask][i] + dist[i][j]);
                }
            }
        }
    }

    vector<ld> minTotal(1 << k, INF);
    for(int mask = 0; mask < (1<<k); mask++)
        for(int i = 0; i < n; i++)
            minTotal[mask] = min(minTotal[mask], minDist[mask][i]);

    cout << minTotal[(1<<k) - 1] << '\n';

    return 0;
}

//rooted in i and mask terminals nodes have been joined