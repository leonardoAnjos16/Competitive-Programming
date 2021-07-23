#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 2e8 + 5;

int N, M;
vector<pair<int, int>> apples;
vector<vector<vector<int>>> memo;

int vitamin(int used_spell = 0, int i = 0, int price = 0) {
    if (price > M) return -INF;
    if (i >= N) return 0;

    int &ans = memo[used_spell][i][price];
    if (~ans) return ans;

    ans = vitamin(used_spell, i + 1, price);
    ans = max(ans, apples[i].first + vitamin(used_spell, i + 1, price + apples[i].second));
    if (!used_spell) ans = max(ans, apples[i].first + vitamin(1, i + 1, price + apples[i].second / 2));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N >> M;
        apples.resize(N);

        for (int i = 0; i < N; i++) {
            int V, P;
            cin >> V >> P;
            apples[i] = make_pair(V, P);
        }

        memo.assign(2, vector<vector<int>>(N + 5, vector<int>(M + 5, -1)));

        int ans = vitamin();
        cout << ans << "\n";
    }
}