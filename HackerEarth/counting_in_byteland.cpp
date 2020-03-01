#include <bits/stdc++.h>

using namespace std;

#define MAX 105

typedef long long int ll;

ll bit[MAX][MAX][MAX];
int size;

int LSO(int i) { return (i & -i); }

void update(int x, int y, int z, ll v) {
    for (int i = x + 1; i <= size + 1; i += LSO(i))
        for (int j = y + 1; j <= size + 1; j += LSO(j))
            for (int k = z + 1; k <= size + 1; k += LSO(k))
                bit[i][j][k] += v;
}

ll query(int x, int y, int z) {
    ll sum = 0;
    for (int i = x + 1; i > 0; i -= LSO(i))
        for (int j = y + 1; j > 0; j -= LSO(j))
            for (int k = z + 1; k > 0; k -= LSO(k))
                sum += bit[i][j][k];
               
    return sum;
}

ll query(int x, int y, int z, int X, int Y, int Z) {
    ll sum = query(X, Y, Z);
    sum -= query(x - 1, Y, Z);
    sum -= query(X, Y, z - 1);
    sum += query(x - 1, Y, z - 1);
    sum -= query(X, y - 1, Z);
    sum += query(x - 1, y - 1, Z);
    sum += query(X, y - 1, z - 1);
    sum -= query(x - 1, y - 1, z - 1);
    return sum;
}

int main() {
    int num_queries;
    scanf("%d %d", &size, &num_queries);
    
    for (int i = 0; i <= size + 1; i++)
        for (int j = 0; j <= size + 1; j++)
            for (int k = 0; k <= size + 1; k++)
                bit[i][j][k] = 0;
                
    ll total_pop = 0;
    while (num_queries--) {
        int type, x, y, z;
        scanf("%d %d %d %d", &type, &x, &y, &z);
        
        if (type == 1) {
            ll v; scanf("%lld", &v);
            total_pop += v;
            update(x, y, z, v);
        } else {
            int X, Y, Z; scanf("%d %d %d", &X, &Y, &Z);
            ll population = query(x, y, z, X, Y, Z);
            ll answer = total_pop - population;
            printf("%lld\n", answer);
        }
    }
}