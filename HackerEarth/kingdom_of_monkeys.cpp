#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
class UnionFind {
    private:
        vector<int> ds, rank;
        
    public:
        UnionFind(int num_vertices) {
            ds.reserve(num_vertices);
            rank.assign(num_vertices, 0);
            for (int i = 0; i < num_vertices; i++) ds[i] = i;
        }
        
        int find(int v) {
            if (ds[v] == v) return v;
            else ds[v] = find(ds[v]);
            return ds[v];
        }
        
        void unite(int v1, int v2) {
            int r1 = find(v1), r2 = find(v2);
            if (r1 != r2) {
                if (rank[r1] > rank[r2]) ds[r2] = r1;
                else ds[r1] = r2;
                
                if (rank[r1] == rank[r2]) rank[r2]++;
            }
        }
};
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        int num_monkeys, num_rituals;
        scanf("%d %d", &num_monkeys, &num_rituals);
        
        UnionFind ds(num_monkeys);
        for (int i = 0; i < num_rituals; i++) {
            int m1, m2; scanf("%d %d", &m1, &m2);
            ds.unite(m1 - 1, m2 - 1);
        }
        
        vector<ll> bananas(num_monkeys);
        for (int i = 0; i < num_monkeys; i++)
            scanf("%lld", &bananas[i]);
            
        vector<ll> bananas_per_team(num_monkeys, 0);
        ll max = INT_MIN;
        
        for (int i = 0; i < num_monkeys; i++) {
            int root = ds.find(i);
            bananas_per_team[root] += bananas[i];
            if (bananas_per_team[root] > max) max = bananas_per_team[root];
        }
        
        printf("%lld\n", max);
    }
}