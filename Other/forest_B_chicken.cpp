#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> forest;
vector<int> labels, values;

void get_labels(int node, int &label) {
    labels[node] = label++;
    for (int child: forest[node])
        get_labels(child, label);
}

void get_values(int node, int &value) {
    values[node] = value;
    for (int child: forest[node]) {
        get_values(child, value);
        values[node] = max(values[node], values[child] + 1);
    }

    value = values[node] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    forest.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p) forest[p - 1].push_back(i);
    }

    int label = 1;
    labels.assign(n, -1);

    for (int i = 0; i < n; i++)
        if (labels[i] == -1)
            get_labels(i, label);

    int value = 1;
    values.assign(n, -1);

    for (int i = 0; i < n; i++)
        if (values[i] == -1)
            get_values(i, value);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[labels[i] - 1] = values[i];

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}