#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;

int N;
vector<pair<int, int>> participants;
vector<vector<long>> memo;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first + a.second > b.first + b.second;
}

long height(int use, int i = 0) {
    if (!use) return 0LL;
    if (i >= N) return INF;

    long &ans = memo[use][i];
    if (~ans) return ans;

    ans = height(use, i + 1);
    if (participants[i].first >= height(use - 1, i + 1))
        ans = min(ans, participants[i].second + height(use - 1, i + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    participants.resize(N);

    for (int i = 0; i < N; i++) {
        int H, P;
        cin >> H >> P;
        participants[i] = make_pair(H, P);
    }

    sort(participants.begin(), participants.end(), comp);
    memo.assign(N + 5, vector<long>(N + 5, -1LL));

    int ans = 0;
    for (int i = 0; i <= N; i++)
        if (height(i) < INF) ans = i;

    cout << ans << "\n";
}