#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;

        vector<int> S(M);
        for (int i = 0; i < M; i++)
            cin >> S[i];

        vector<vector<int>> P(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> P[i][j];

        int ans = 0;
        vector<int> changed(M, 0);

        priority_queue<pair<int, int>> models;
        for (int i = 0; i < M; i++)
            models.emplace(0, i);

        for (int i = 0; i < N; i++) {
            multiset<int> dresses;
            for (int j = 0; j < M; j++)
                dresses.insert(P[i][j]);

            vector<bool> done(M, false);
            while (!models.empty()) {
                int model = models.top().second;
                models.pop();

                auto it = dresses.lower_bound(S[model]);
                if (it != dresses.end() && *it == S[model]) {
                    done[model] = true;
                    dresses.erase(it);
                }
            }

            for (int j = 0; j < M; j++) {
                if (!done[j]) {
                    auto it = dresses.begin();
                    S[j] = *it;

                    if ((int) dresses.size() > 1)
                        dresses.erase(it);

                    if (changed[j])
                        ans++;
                    
                    changed[j]++;
                }
            }

            for (int j = 0; j < M; j++)
                models.emplace(changed[j], j);
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}