#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
vector<int> s;
vector<int> memo;

int models(int i) {
    int &ans = memo[i];
    if (~ans) return ans;

    ans = 1;
    int nxt = 2 * i;

    while (nxt <= n) {
        if (s[nxt - 1] > s[i - 1])
            ans = max(ans, 1 + models(nxt));

        nxt += i;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        s.resize(n);

        for (int i = 0; i < n; i++)
            cin >> s[i];

        memo.assign(n + 5, -1);

        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = max(ans, models(i));

        cout << ans << "\n";
    }
}