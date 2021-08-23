#include <bits/stdc++.h>

using namespace std;

#define long long long int

int moves(string a, string b) {
    int n = a.size(), m = b.size();

    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        while (j < m && b[j] != a[i])
            j++, ans++;

        if (j < m) i++, j++;
    }

    ans += n - i + m - j;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> powers;
    for (int i = 0; i <= 62; i++)
        powers.push_back(to_string(1LL << i));

    int t; cin >> t;
    while (t--) {
        string n; cin >> n;

        int ans = INT_MAX;
        for (auto p: powers)
            ans = min(ans, moves(p, n));

        cout << ans << "\n";
    }
}