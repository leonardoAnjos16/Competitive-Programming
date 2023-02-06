#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string ans = "a";
    for (int i = 2; (i >> 1) < n; i <<= 1) {
        for (int j = 1; j < (i >> 1); j++)
            ans += ans[j - 1];

        ans += (char) (ans[(i >> 1) - 1] + 1);
    }

    ans = ans.substr(0, n);
    cout << ans << "\n";
}