#include <bits/stdc++.h>

using namespace std;

#define long long long int

int ops(string &last, string &curr) {
    int m = last.size(), n = curr.size();
    if (m == n) {
        int ans = 0;
        for (int i = 0; i < m; i++)
            ans += last[i] != curr[i];

        return ans;
    }

    assert(n == 2 * m);

    int ans = 1;
    for (int i = 0; i < m; i++) {
        if (last[i] != curr[i] && last[i] != curr[m + i]) {
            if (curr[i] == curr[m + i]) ans++;
            else ans += 2;
        }
        else if (last[i] != curr[i] || last[i] != curr[m + i]) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    string last;
    cin >> last;

    for (int i = 1; i < n; i++) {
        string curr; cin >> curr;
        ans += ops(last, curr);
        last = curr;
    }

    cout << ans << "\n";
}