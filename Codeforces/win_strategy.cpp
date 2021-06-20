#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 2e6 + 5;

int n, L;
vector<pair<int, int>> problems;
vector<vector<int>> memo;

int max_problems(int i = 0, int t = 0) {
    if (i >= n || t > L) return 0;

    int &ans = memo[i][t];
    if (~ans) return ans;

    ans = max(max_problems(i + 1, t), max_problems(i, t + 1));
    if (problems[i].first <= t && t + problems[i].second <= L + 1)
        ans = max(ans, max_problems(i + 1, t + problems[i].second) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> n >> L;
        problems.resize(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            problems[i] = make_pair(a, b);
        }

        memo.assign(n + 5, vector<int>(L + 5, -1));

        int ans = max_problems();
        cout << ans << "\n";
    }
}