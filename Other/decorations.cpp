#include <bits/stdc++.h>

using namespace std;

#define long long long int

int m;
vector<string> combs;
vector<vector<int>> memo;

bool starts_with(string &s, int p) {
    if (combs[p].size() > s.size() + 1) return false;

    for (int i = 1, n = combs[p].size(); i < n; i++)
        if (s[i - 1] != combs[p][i]) return false;

    return true;
}

int count(int l, int p) {
    if (!l) return 1;

    int &ans = memo[l][p];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < m; i++)
        if (starts_with(combs[i], p))
            ans += count(l - 1, i);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    while (cin >> n >> l >> m, n || l || m) {
        combs.resize(m);
        for (int i = 0; i < m; i++)
            cin >> combs[i];

        if (l < combs[0].size()) {
            cout << "0\n";
            continue;
        }

        memo.assign(l + 5, vector<int>(m + 5, -1));

        int ans = 0;
        for (int i = 0; i < m; i++)
            ans += count(l - (int) combs[i].size(), i);

        cout << ans << "\n";
    }
}