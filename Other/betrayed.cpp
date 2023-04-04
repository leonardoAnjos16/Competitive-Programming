#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const int INF = 1e9 + 5;
const ldouble EPS = 1e-9;

vector<vector<int>> tree;

int deepest(vector<int> &depth, int node = 0, int parent = -1) {
    int ans = node;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;

            int aux = deepest(depth, child, node);
            if (depth[aux] > depth[ans])
                ans = aux;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(4) << fixed;

    int T; cin >> T;
    while (T--) {
        int C, K;
        cin >> C >> K;

        vector<int> safe(C, 0), size(C);
        for (int i = 0; i < C; i++) {
            cin >> size[i];

            tree.assign(size[i], vector<int>());
            for (int j = 1; j < size[i]; j++) {
                int a; cin >> a;
                tree[j].push_back(a - 1);
                tree[a - 1].push_back(j);
            }

            vector<int> da(size[i], 0);
            int a = deepest(da);

            da[a] = 0;
            int b = deepest(da, a);

            vector<int> db(size[i], 0);
            deepest(db, b);

            for (int j = 0; j < size[i]; j++)
                if (max(da[j], db[j]) <= K)
                    safe[i]++;

            assert(4 * safe[i] >= size[i]);
        }

        vector<ldouble> E(C + 1, 0.0L);
        for (int i = 1; i <= C; i++) {
            ldouble p = 1.0L * safe[i - 1] / size[i - 1];
            E[i] = E[i - 1] / p - 3.0L + 4.0L / p;
        }

        ldouble ans = E[C];
        cout << ans << "\n";
    }
}