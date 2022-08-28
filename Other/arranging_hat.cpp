#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

int n, m;
vector<string> v;
vector<vector<vector<vector<int>>>> memo, nxt;

int changes(int l, int r, int col = 0, int d = 0) {
    if (l > r || col >= m) return 0;
    if (d >= 10) return INF;

    int &ans = memo[l][r][col][d];
    if (~ans) return ans;

    ans = INF;
    int cnt = 0;

    for (int i = l - 1; i <= r; i++) {
        if (i >= l && v[i][col] != (char) ('0' + d)) cnt++;

        int aux = cnt + changes(l, i, col + 1) + changes(i + 1, r, col, d + 1);
        if (aux < ans) {
            ans = aux;
            nxt[l][r][col][d] = i;
        }
    }

    return ans;
}

void build(int l, int r, int col = 0, int d = 0) {
    if (l > r || col >= m || d >= 10) return;

    int i = nxt[l][r][col][d];
    for (int j = l; j <= i; j++)
        v[j][col] = (char) ('0' + d);

    build(l, i, col + 1);
    build(i + 1, r, col, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    memo.assign(n + 5, vector<vector<vector<int>>>(n + 5, vector<vector<int>>(m + 5, vector<int>(10, -1))));
    nxt.assign(n + 5, vector<vector<vector<int>>>(n + 5, vector<vector<int>>(m + 5, vector<int>(10, -1))));

    changes(0, n - 1);
    build(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";
}