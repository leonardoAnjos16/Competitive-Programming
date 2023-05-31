#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

vector<int> K, id;
vector<vector<int>> g;
vector<int> memo;

int youngest(int v) {
    int &ans = memo[v];
    if (~ans) return ans;

    ans = INF;
    for (int u: g[v]) {
        int manager = id[u];
        ans = min(ans, K[manager]);
        ans = min(ans, youngest(u));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, I;
    cin >> N >> M >> I;

    K.resize(N);
    id.resize(N);

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> K[i];
        id[i] = pos[i] = i;
    }

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        g[Y - 1].push_back(X - 1);
    }

    memo.assign(N + 5, -1);
    while (I--) {
        char op; cin >> op;
        if (op == 'T') {
            int A, B;
            cin >> A >> B;

            swap(id[pos[A - 1]], id[pos[B - 1]]);
            swap(pos[A - 1], pos[B - 1]);
            memo.assign(N + 5, -1);
        } else {
            int E; cin >> E;

            int ans = youngest(pos[E - 1]);
            if (ans >= INF) cout << "*\n";
            else cout << ans << "\n";
        }
    }
}