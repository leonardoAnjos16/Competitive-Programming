#include "bits/stdc++.h"
using namespace std;

#define int long long

const int m = 4;
const int MOD = 1e9 + 7;

class Matrix{
    public:
        int mat[m][m];
        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++){
                    ans.mat[i][j] = 0;
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k] % MOD) * (p.mat[k][j] % MOD)) % MOD;
                }
            return ans;
        }
};

Matrix aux = {2, 4, 0, 2, 1, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 2};

Matrix fexp(Matrix ans, int b){
    while(b){
        if(b & 1) ans = aux*ans;
        aux = aux*aux;
        b >>= 1;
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) cout << "2\n";
    else{
        Matrix ans;
        ans.mat[0][0] = 6;
        ans.mat[1][0] = 1;
        ans.mat[2][0] = 0;
        ans.mat[3][0] = 2;

        ans = fexp(ans, n - 2);
        int sum = (4*ans.mat[0][0] % MOD + 2*ans.mat[2][0] % MOD) % MOD;
        cout << sum << '\n';
    }
}