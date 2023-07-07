#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    s = "-" + s + s;
    vector<vector<int>> ps(3, vector<int>(2 * n + 1, 0));

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j < 3; j++)
            ps[j][i] = ps[j][i - 1];

        ps[s[i] - 'A'][i]++;
    }

    int as = ps[0][n];
    int bs = ps[1][n];
    int cs = ps[2][n];

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int abc = as - ps[0][i + as - 1] + ps[0][i - 1];
        abc += bs - ps[1][i + as + bs - 1] + ps[1][i + as - 1];
        abc += cs - ps[2][i + as + bs + cs - 1] + ps[2][i + as + bs - 1];

        int acb = as - ps[0][i + as - 1] + ps[0][i - 1];
        acb += cs - ps[2][i + as + cs - 1] + ps[2][i + as - 1];
        acb += bs - ps[1][i + as + cs + bs - 1] + ps[1][i + as + cs - 1];

        ans = min({ ans, abc, acb });
    }

    cout << ans << "\n";
}