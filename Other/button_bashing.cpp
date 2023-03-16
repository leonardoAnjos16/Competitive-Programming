#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 3600;

int n;
vector<int> b;
int dists[MAX + 1];

void get_dists() {
    memset(dists, -1, sizeof dists);
    dists[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            int u = min(max(v + b[i], 0), MAX);
            if (dists[u] == -1) {
                q.push(u);
                dists[u] = dists[v] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int t;
        cin >> n >> t;

        b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        get_dists();

        int extra = 0;
        while (t <= MAX && dists[t] == -1) t++, extra++;
        assert(t <= MAX);

        cout << dists[t] << " " << extra << "\n";
    }
}