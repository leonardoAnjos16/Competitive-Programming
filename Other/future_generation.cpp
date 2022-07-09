#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;

int N;
vector<vector<string>> names;
vector<vector<int>> memo;

int length(int i = 0, int j = 0) {
    if (i >= N) return 0;
    if (j >= (int) names[i].size()) return -INF;

    int &ans = memo[i][j];
    if (~ans) return ans;

    int nj = upper_bound(names[i + 1].begin(), names[i + 1].end(), names[i][j]) - names[i + 1].begin();
    ans = max(length(i, j + 1), length(i + 1, nj) + (int) names[i][j].size());

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int mx = 0;
    names.assign(N + 1, vector<string>());

    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        int size = S.size();
        mx = max(mx, size);

        for (int j = 1; j < (1 << size); j++) {
            string name = "";
            for (int k = 0; k < size; k++)
                if (j & (1 << k)) name += S[k];

            names[i].push_back(name);
        }

        sort(names[i].begin(), names[i].end());
    }

    memo.assign(N + 5, vector<int>(1 << mx, -1));

    int ans = length();
    if (ans <= 0) cout << "-1\n";
    else cout << ans << "\n";
}