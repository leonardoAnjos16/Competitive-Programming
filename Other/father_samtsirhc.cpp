#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> start(N, make_pair(0, 0));
    vector<vector<pair<int, int>>> end(N, vector<pair<int, int>>());

    for (int i = 0; i < M; i++) {
        int I, J;
        cin >> I >> J;

        if (i & 1) start[I - 1].second++;
        else start[I - 1].first++;

        end[J - 1].emplace_back(i & 1, J - I + 1);
    }

    int cnts[2] = {0};
    llong sums[2] = {0LL};
    vector<llong> gifts(N, 0LL);

    bool win = true;
    for (int i = 0; i < N && win; i++) {
        cnts[0] += start[i].first;
        cnts[1] += start[i].second;
        sums[0] += start[i].first;
        sums[1] += start[i].second;

        gifts[i] = sums[0] - sums[1];
        if (gifts[i] < 0LL) win = false;

        for (auto [type, value]: end[i]) {
            cnts[type]--;
            sums[type] -= value;
        }

        sums[0] += cnts[0];
        sums[1] += cnts[1];
    }

    cout << (win ? "ALL I WANT FOR CHRISTMAS IS YOU" : "UOY SI SAMTSIRHC ROF TNAW I LLA") << "\n";
}