#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> reachable;
vector<vector<int>> memo;

int services(int available, int i = 0) {
    if (!available || i > N) return 0;

    int &ans = memo[available][i];
    if (~ans) return ans;

    ans = 0;
    int chosen = available;

    while (chosen) {
        if (reachable[chosen] == (1 << N) - 1)
            ans = max(ans, services(available ^ chosen, i + 1) + 1);
            
        chosen = (chosen - 1) & available;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_case = 1;
    while (cin >> N, N) {
        vector<int> neighbours(N, 0);
        for (int i = 0; i < N; i++) {
            int m; cin >> m;
            while (m--) {
                int neighbour; cin >> neighbour;
                neighbours[i] |= (1 << neighbour);
            }
        }

        reachable.assign(1 << N, 0);
        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < N; j++)
                if (i & (1 << j)) {
                    reachable[i] |= (1 << j);
                    reachable[i] |= neighbours[j];
                }

        memo.assign((1 << N) + 5, vector<int>(N + 5, -1));

        int ans = services((1 << N) - 1);
        cout << "Case " << num_case++ << ": " << ans << "\n";
    }
}