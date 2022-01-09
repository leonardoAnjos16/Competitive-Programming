#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8 + 5;

int N, K, L;
vector<pair<int, int>> members, items;
vector<vector<int>> memo;

int knapsack(int c, int i = 0, int w = 0) {
    if (w > c) return -INF;
    if (i >= K) return 0;

    int &ans = memo[i][w];
    if (~ans) return ans;

    return ans = max(knapsack(c, i + 1, w), knapsack(c, i + 1, w + items[i].first) + items[i].second);
}

int choose_members(int i = 0, int w = 0) {
    if (w > L) return -INF;
    if (i >= N) return 0;

    int &ans = memo[i][w];
    if (~ans) return ans;

    return ans = max(choose_members(i + 1, w), members[i].first + choose_members(i + 1, w + members[i].second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> L;

    members.resize(N);
    for (int i = 0; i < N; i++) {
        int c, w;
        cin >> c >> w;
        members[i] = make_pair(c, w);
    }

    items.resize(K);
    for (int i = 0; i < K; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }

    for (int i = 0; i < N; i++) {
        memo.assign(K + 5, vector<int>(members[i].first + 5, -1));
        members[i].first = knapsack(members[i].first);
    }

    memo.assign(N + 5, vector<int>(L + 5, -1));

    int ans = choose_members();
    cout << ans << "\n";
}