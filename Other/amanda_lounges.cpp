#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool bicolorable(vector<vector<int>> &g, vector<int> &color, int cnt[2], int v, int c = 0) {
    if (color[v] != -1)
        return color[v] == c;

    cnt[c]++;
    color[v] = c;

    for (auto u: g[v])
        if (!bicolorable(g, color, cnt, u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> lounge(n, -1);
    vector<vector<int>> ones(n, vector<int>());

    bool possible = true;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c != 1) {
            bool aux = c == 2;
            if (lounge[a - 1] != -1 && lounge[a - 1] != aux) possible = false;
            if (lounge[b - 1] != -1 && lounge[b - 1] != aux) possible = false;
            lounge[a - 1] = lounge[b - 1] = aux;
        } else {
            ones[a - 1].push_back(b - 1);
            ones[b - 1].push_back(a - 1);
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (lounge[i] != -1)
            q.push(i);

    while (!q.empty() && possible) {
        int v = q.front(); q.pop();
        for (auto u: ones[v]) {
            if (lounge[u] == lounge[v]) {
                possible = false;
                break;
            }

            if (lounge[u] == -1) {
                q.push(u);
                lounge[u] = !lounge[v];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (lounge[i] == 1) ans++;

    int cnt[2] = {0};
    for (int i = 0; i < n && possible; i++)
        if (lounge[i] == -1) {
            possible &= bicolorable(ones, lounge, cnt, i);
            ans += min(cnt[0], cnt[1]);
            cnt[0] = cnt[1] = 0;
        }

    if (!possible) cout << "impossible\n";
    else cout << ans << "\n";
}