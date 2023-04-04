#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

vector<vector<int>> tree;
vector<ldouble> a, b;
vector<int> depth;

void init(int node, int &leaves) {
    if (tree[node].empty()) {
        a[node] = 1.0L;
        b[node] = leaves++;
    } else {
        depth[tree[node][0]] = depth[tree[node][1]] = depth[node] + 1;
        init(tree[node][0], leaves);
        init(tree[node][1], leaves);

        a[node] = (a[tree[node][0]] + a[tree[node][1]] )/ 2.0L;
        b[node] = (b[tree[node][0]] + b[tree[node][1]]) / 2.0L;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(4) << fixed;

    int T; cin >> T;
    while (T--) {
        int N, q;
        cin >> N >> q;

        vector<bool> root(N, true);
        tree.assign(N, vector<int>());

        for (int i = 0; i < N; i++) {
            int k; cin >> k;
            if (k) {
                int L, R;
                cin >> L >> R;

                tree[i].push_back(L - 1);
                tree[i].push_back(R - 1);
                root[L - 1] = root[R - 1] = false;
            }
        }

        a.resize(N);
        b.resize(N);
        depth.assign(N, 0);

        int rt = -1;
        bool found = false;

        for (int i = 0; i < N; i++)
            if (root[i]) {
                assert(!found);
                found = true;

                int leaves = 0;
                init(i, leaves);
                rt = i;
            }

        assert(found);
        while (q--) {
            int r, V, H, U;
            cin >> r >> V >> H >> U;

            ldouble xl = -b[rt] * (H + 2 * r) / a[rt];
            ldouble x = xl * a[U - 1] + (H + 2 * r) * b[U - 1];
            ldouble y = -depth[U - 1] * (V + 2 * r);

            cout << x << " " << y << "\n";
        }
    }
}