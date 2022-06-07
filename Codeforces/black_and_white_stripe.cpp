#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s; cin >> s;

        vector<int> whites(n + 1, 0);
        for (int i = 1; i <= n; i++)
            whites[i] = whites[i - 1] + (s[i - 1] == 'W');

        int ans = INT_MAX;
        for (int i = k; i <= n; i++)
            ans = min(ans, whites[i] - whites[i - k]);

        cout << ans << "\n";
    }
}