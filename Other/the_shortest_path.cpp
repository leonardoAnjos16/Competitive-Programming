#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        int mn = INT_MAX;
        vector<tuple<int, int, int>> edges(M);

        for (int i = 0; i < M; i++) {
            int U, V, C;
            cin >> U >> V >> C;

            mn = min(mn, C);
            edges[i] = make_tuple(U - 1, V - 1, C);
        }

        if (mn >= 0) cout << mn << "\n";
        else {
            bool changed = false;
            vector<llong> dists(N, 0LL);

            for (int i = 0; i < N; i++) {
                changed = false;
                for (auto [u, v, w]: edges)
                    if (dists[u] + w < dists[v]) {
                        changed = true;
                        dists[v] = dists[u] + w;
                    }
            }

            if (changed) cout << "-inf\n";
            else {
                llong ans = LLONG_MAX;
                for (int i = 0; i < N; i++)
                    ans = min(ans, dists[i]);

                cout << ans << "\n";
            }
        }
    }
}