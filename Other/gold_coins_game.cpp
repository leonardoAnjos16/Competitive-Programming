#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int moves(int x, int y) {
    queue<int> q;
    q.push(x);

    int dists[MAX];
    memset(dists, -1, sizeof dists);
    dists[x] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == y) return dists[v];

        if (v < y && dists[3 * v] == -1) {
            dists[3 * v] = dists[v] + 1;
            q.push(3 * v);
        }

        if (v > 0 && dists[v - 1] == -1) {
            dists[v - 1] = dists[v] + 1;
            q.push(v - 1);
        }
    }

    return dists[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int ans = moves(x, y);
    cout << ans << "\n";
}