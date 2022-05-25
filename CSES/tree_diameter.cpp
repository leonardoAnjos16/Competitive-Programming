#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<int> distances;

void get_distances(int node = 0, int parent = -1) {
    for (auto child: tree[node])
        if (child != parent) {
            distances[child] = distances[node] + 1;
            get_distances(child, node);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    distances.assign(n, 0);
    get_distances();

    int node = max_element(distances.begin(), distances.end()) - distances.begin();
    distances.assign(n, 0);
    get_distances(node);

    int ans = *max_element(distances.begin(), distances.end());
    cout << ans << "\n";
}