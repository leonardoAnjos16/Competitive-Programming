#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int T, P;
vector<int> E, D, S;
vector<vector<vector<int>>> kmemo;
vector<vector<int>> memo;

int knapsack(int energy, int l, int r) {
    if (energy < 0) return -INF;
    if (l > r) return 0;

    int &ans = kmemo[energy][l][r];
    if (~ans) return ans;

    ans = knapsack(energy, l + 1, r);
    ans = max(ans, knapsack(energy - D[l], l + 1, r) + S[l]);

    return ans;
}

int score(int team = 0, int i = 0) {
    if (team + 1 >= (1 << T) || i >= P) return 0;

    int &ans = memo[team][i];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j < T; j++)
        if (!(team & (1 << j)))
            for (int k = i; k < P; k++)
                ans = max(ans, score(team | (1 << j), k + 1) + knapsack(E[j], i, k));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T >> P;

    E.resize(T);
    int mx = INT_MIN;

    for (int i = 0; i < T; i++) {
        cin >> E[i];
        mx = max(mx, E[i]);
    }

    D.resize(P);
    for (int i = 0; i < P; i++)
        cin >> D[i];

    S.resize(P);
    for (int i = 0; i < P; i++)
        cin >> S[i];

    kmemo.assign(mx + 5, vector<vector<int>>(P + 5, vector<int>(P + 5, -1)));
    memo.assign((1 << T) + 5, vector<int>(P + 5, -1));

    int ans = score();
    cout << ans << "\n";
}