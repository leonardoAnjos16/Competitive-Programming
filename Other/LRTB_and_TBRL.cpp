#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

vector<int> nxt;
vector<bool> vis;

void traverse(int v) {
    if (vis[v]) return;

    vis[v] = true;
    traverse(nxt[v]);
}

long exp(int b, int n) {
    if (!n) return 1;

    long ans = exp(b, n >> 1);
    ans = (ans * ans) % MOD;

    if (n & 1)
        ans = (ans * b) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, C;
    cin >> N >> R >> C;

    int v = 0;
    nxt.resize(R * C);

    for (int i = C - 1; i >= 0; i--)
        for (int j = 0; j < R; j++)
            nxt[v++] = j * C + i;

    int cnt = 0;
    vis.assign(R * C, false);

    for (int i = 0; i < R * C; i++)
        if (!vis[i]) {
            cnt++;
            traverse(i);
        }

    int ans = exp(N, cnt);
    cout << ans << "\n";
}