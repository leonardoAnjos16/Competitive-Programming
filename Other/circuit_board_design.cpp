#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1.0);

vector<int> weight;
vector<vector<int>> tree;
vector<pair<long double, long double>> ans;

long double dist(pair<long double, long double> a, pair<long double, long double> b) {
    long double dx = b.first - a.first;
    long double dy = b.second - a.second;
    return sqrt(dx * dx + dy * dy);
}

void get_weights(int node = 0, int parent = -1) {
    if (~parent && (int) tree[node].size() <= 1) weight[node] = 0;
    else {
        weight[node] = 0;
        for (auto child: tree[node])
            if (child != parent) {
                get_weights(child, node);
                weight[node] += 1 + weight[child];
            }
    }
}

void solve(int node = 0, int parent = -1, long double x = 0.0, long double y = 0.0, long double init_angle = 0.0, long double end_angle = 2 * PI) {
    if (~parent && (int) tree[node].size() <= 1) ans[node] = make_pair(x, y);
    else {
        int children = tree[node].size() - (~parent ? 1 : 0);
        long double angle = (end_angle - init_angle) / weight[node];

        long double last_angle = init_angle;
        for (int child: tree[node])
            if (child != parent) {
                long double new_init = last_angle;
                long double new_end = new_init + angle * (weight[child] + 1);

                long double aux = new_init + angle * (weight[child] + 1) / 2.0;
                solve(child, node, x + cosl(aux), y + sinl(aux), new_init, new_end);
                last_angle = new_end;
            }

        ans[node] = make_pair(x, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    weight.resize(n);
    get_weights();

    if (n == 1) cout << 0.0 << " " << 0.0 << "\n";
    else {
        ans.assign(n, make_pair(0.0, 0.0));
        solve();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    assert(dist(ans[i], ans[j]) >= 1e-6);

        for (auto [x, y]: ans)
            cout << x << " " << y << "\n";
    }
}