#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] != a[n - i - 1][n - j - 1])
                    cnt++;

        assert(!(cnt & 1));
        cnt >>= 1;

        if (cnt > k) cout << "NO\n";
        else if (!((k - cnt) & 1) || (n & 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}