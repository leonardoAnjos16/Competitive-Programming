#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 15;
 
int N, M, X1, Y1, X2, Y2;
int A[MAX][MAX];
 
bool okay;
 
void backtrack(int x, int y) {
    if (x == X2 && y == Y2) okay = true;
    else {
        if (!okay && x > 1 && A[x - 1][y] > A[x][y]) backtrack(x - 1, y);
        if (!okay && y > 1 && A[x][y - 1] > A[x][y]) backtrack(x, y - 1);
        if (!okay && x < N && A[x + 1][y] > A[x][y]) backtrack(x + 1, y);
        if (!okay && y < M && A[x][y + 1] > A[x][y]) backtrack(x, y + 1);
    }
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d", &N, &M, &X1, &Y1, &X2, &Y2);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &A[i][j]);
 
        okay = false;
        backtrack(X1, Y1);
 
        printf("%s\n", okay ? "YES" : "NO");
    }
}