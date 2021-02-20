#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        tuple<int, int, int> A[MAX];
        for (int i = 0; i < N; i++) {
            int S, E; cin >> S >> E;
            A[i] = { S, E, i };
        }

        sort(A, A + N);
        cout << "Case #" << t << ": ";

        bool possible = true;
        vector<tuple<int, int, int>> cameron, jamie;

        for (int i = 0; i < N && possible; i++) {
            if (cameron.empty() || get<1>(cameron.back()) <= get<0>(A[i]))
                cameron.push_back(A[i]);
            else if (jamie.empty() || get<1>(jamie.back()) <= get<0>(A[i]))
                jamie.push_back(A[i]);
            else
                possible = false;
        }

        if (!possible) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        string ans(N, '-');
        for (auto t: cameron) ans[get<2>(t)] = 'C';
        for (auto t: jamie) ans[get<2>(t)] = 'J';
        cout << ans << "\n";
    }
}