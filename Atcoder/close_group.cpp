#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;

int N;
vector<bool> possible;
vector<int> memo;

int connected_components(int available) {
    if (!available) return 0;

    int &ans = memo[available];
    if (~ans) return ans;

    ans = INF;
    int chosen = available;

    while (chosen) {
        if (possible[chosen])
            ans = min(ans, connected_components(available ^ chosen) + 1);

        chosen = (chosen - 1) & available;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    vector<vector<bool>> connected(N, vector<bool>(N, false));
    while (M--) {
        int A, B;
        cin >> A >> B;
        connected[A - 1][B - 1] = connected[B - 1][A - 1] = true;
    }

    for (int i = 0; i < N; i++)
        connected[i][i] = true;

    possible.assign(1 << N, true);
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N && possible[i]; j++) if (i & (1 << j))
            for (int k = 0; k < N && possible[i]; k++) if (i & (1 << k))
                if (!connected[j][k])
                    possible[i] = false;

    memo.assign((1 << N) + 5, -1LL);

    int ans = connected_components((1 << N) - 1);
    cout << ans << "\n";
}