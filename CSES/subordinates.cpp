#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<int> subordinates;

void get_subordinates(int node = 0) {
    subordinates[node] = 0;
    for (auto child: tree[node]) {
        get_subordinates(child);
        subordinates[node] += subordinates[child] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int boss; cin >> boss;
        tree[boss - 1].push_back(i);
    }

    subordinates.resize(n);
    get_subordinates();

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << subordinates[i];
    }

    cout << "\n";
}