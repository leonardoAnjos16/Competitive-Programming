#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

string s;
int memo[(1 << 4) + 5][5][25];

int moves(int status = 0, int last = 4, int cnt = 0) {
    if (status + 1 == (1 << 4)) return cnt;
    if (cnt >= 20) return INF;

    int &ans = memo[status][last][cnt];
    if (~ans) return ans;

    ans = INF;
    for (int i = 0; i < 4; i++)
        if (last == -1 || s[i] != s[last])
            ans = min(ans, moves(status ^ (1 << i), i, cnt + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> s;

        memset(memo, -1, sizeof memo);

        int ans = moves();
        if (ans >= INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}