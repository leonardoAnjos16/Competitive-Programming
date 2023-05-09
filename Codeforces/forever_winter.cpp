#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> deg(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            deg[u - 1]++;
            deg[v - 1]++;
        }

        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++)
            cnt[deg[i]]++;

        vector<int> degs;
        for (int i = 2; i < n; i++)
            if (cnt[i])
                degs.push_back(i);

        assert(!degs.empty());
        if ((int) degs.size() == 1) {
            int x = degs[0], y = degs[0] - 1;
            cout << x << " " << y << "\n";
        } else {
            assert((int) degs.size() == 2);
            if (cnt[degs[0]] > cnt[degs[1]])
                swap(degs[0], degs[1]);

            assert(cnt[degs[0]] == 1);

            int x = degs[0], y = degs[1] - 1;
            cout << x << " " << y << "\n";
        }
    }
}