#include "bits/stdc++.h"
using namespace std;

const int MAXN = 105;

int vis[3*MAXN];
int grid[MAXN][MAXN] = {};

void print(){
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

void calc(){
    for(int i = 0; i <= 100; i++){
        grid[0][i] = grid[i][0] = grid[i][i] = -1;  //posicoes terminais
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){

            memset(vis, 0, sizeof(vis));

            if(grid[i][j] == -1) continue;
            
            //cima
            for(int di = 1; di <= i; di++){
                if(grid[i-di][j] != -1) vis[grid[i-di][j]] = 1;
                //grid[i][j] = max(grid[i][j], grid[i - di][j] + 1);
            }

            //esquerda
            for(int dj = 1; dj <= j; dj++){
                if(grid[i][j-dj] != -1) vis[grid[i][j-dj]] = 1;
                //grid[i][j] = max(grid[i][j], grid[i][j - dj] + 1);
            }

            //diagonal
            for(int d = 1; d <= min(i, j); d++){
                if(grid[i-d][j-d] != -1) vis[grid[i-d][j-d]] = 1;
                //grid[i][j] = max(grid[i][j], grid[i - d][j - d] + 1);
            }

            for(int k = 0; k < 3*MAXN; k++){
                if(!vis[k]){
                    grid[i][j] = k;
                    break;
                }
            }
        }
    }

    //print();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    calc();

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;

        if(u == v || u == 0 || v == 0){
            cout << "Y\n";
            return 0;
        }

        ans ^= grid[u][v];
    }

    if(ans) cout << "Y\n";
    else cout << "N\n";

    return 0;
}