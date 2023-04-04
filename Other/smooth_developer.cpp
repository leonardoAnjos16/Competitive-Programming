#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> need, ans;
vector<bool> use;

bool solve(int node) {
    if (need[node] != -1)
        return need[node];

    need[node] = use[node];
    for (int child: tree[node])
        if (solve(child))
            need[node] = true;

    if (need[node])
        ans.push_back(node);

    return need[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<string> S(N);
        map<string, int> id;
        tree.assign(N, vector<int>());

        for (int i = 0; i < N; i++) {
            int C;
            cin >> S[i] >> C;

            id[S[i]] = i;
            while (C--) {
                string F; cin >> F;
                if (F != S[i])
                    tree[id[F]].push_back(i);
            }
        }

        use.assign(N, false);
        for (int i = 0; i < K; i++) {
            string name; cin >> name;
            use[id[name]] = true;
        }

        ans.clear();
        need.assign(N, -1);

        for (int i = 0; i < N; i++)
            solve(i);

        sort(ans.begin(), ans.end());
        for (int i: ans)
            cout << S[i] << "\n";
    }
}