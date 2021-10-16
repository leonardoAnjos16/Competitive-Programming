#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e8;

int N, M;
vector<tuple<int, int, int, int>> shows;
vector<vector<int>> memo;

int songs(int i = 0, int seen = 0) {
    if (i >= M) return seen == (1 << N) - 1 ? 0 : -INF;

    int &ans = memo[i][seen];
    if (~ans) return ans;

    auto [start, end, bonus, stage] = shows[i];
    int nxt = upper_bound(shows.begin(), shows.end(), make_tuple(end, INF, INF, INF)) - shows.begin();

    return ans = max(songs(i + 1, seen), songs(nxt, seen | (1 << stage)) + bonus);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    M = 0;

    for (int i = 0; i < N; i++) {
        int Mi; cin >> Mi;
        M += Mi;

        while (Mi--) {
            int start, end, bonus;
            cin >> start >> end >> bonus;
            shows.emplace_back(start, end - 1, bonus, i);
        }
    }

    sort(shows.begin(), shows.end());

    memo.assign(M + 5, vector<int>((1 << N) + 5, -1));

    int ans = songs();
    if (ans <= 0) cout << "-1\n";
    else cout << ans << "\n";
}