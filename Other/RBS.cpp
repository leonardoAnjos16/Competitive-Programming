#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<int> balance;
vector<vector<int>> zeros;
vector<int> memo;

int prefixes(int used = 0) {
    if (used + 1 == (1 << n)) return 0;

    int &ans = memo[used];
    if (~ans) return ans;

    int b = 0;
    for (int i = 0; i < n; i++)
        if (used & (1 << i))
            b += balance[i];

    assert(b >= 0);

    ans = 0;
    for (int i = 0; i < n; i++)
        if (!(used & (1 << i))) {
            int cnt = b < (int) zeros[i].size() ? zeros[i][b] : 0;
            if ((int) zeros[i].size() <= b + 1) cnt += prefixes(used | (1 << i));
            ans = max(ans, cnt);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    balance.assign(n, 0);
    zeros.assign(n, vector<int>());

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int cnt = 0;
        for (char c: s) {
            balance[i] += c == '(' ? 1 : -1;
            if (-balance[i] > (int) zeros[i].size()) {
                zeros[i].push_back(cnt);
                cnt = 0;
            }

            cnt += -balance[i] == (int) zeros[i].size();
        }

        zeros[i].push_back(cnt);
    }

    memo.assign((1 << n) + 5, -1);

    int ans = prefixes();
    cout << ans << "\n";
}