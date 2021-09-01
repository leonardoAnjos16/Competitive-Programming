#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> C, to_leaf;
vector<vector<int>> tree;

void get_to_leaf(int v = 0, int p = 0) {
    to_leaf[v] = 0;
    for (auto u: tree[v])
        if (u != p) {
            get_to_leaf(u, v);
            to_leaf[v] = max(to_leaf[v], to_leaf[u]);
        }

    to_leaf[v] += C[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        C.resize(N);
        for (int i = 0; i < N; i++)
            cin >> C[i];

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int A, B;
            cin >> A >> B;

            tree[A - 1].push_back(B - 1);
            tree[B - 1].push_back(A - 1);
        }

        to_leaf.assign(N, 0);
        get_to_leaf();

        int ans = 0;
        if ((int) tree[0].size() < 2)
            for (auto v: tree[0])
                ans = max(ans, to_leaf[v]);
        else
            for (int i = 0; i < (int) tree[0].size(); i++)
                for (int j = i + 1; j < (int) tree[0].size(); j++)
                    ans = max(ans, to_leaf[tree[0][i]] + to_leaf[tree[0][j]]);

        ans += C[0];
        cout << "Case #" << t << ": " << ans << "\n";
    }
}