#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
string s1, s2;
vector<vector<int>> memo;

int matches(int l, int r) {
    if (l >= n || r < 0) return 0;

    int &ans = memo[l][r];
    if (~ans) return ans;

    return ans = matches(l + 1, r - 1) + (s1[l] == s2[r]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> n >> s1 >> s2;

        vector<int> cnt(n);
        cnt[0] = s1[0] == s2[0];

        for (int i = 1; i < n; i++)
            cnt[i] = cnt[i - 1] + (s1[i] == s2[i]);

        memo.assign(n, vector<int>(n, -1));

        int ans = cnt[n - 1], a = 1, b = 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int normal = (i ? cnt[i - 1] : 0) + cnt[n - 1] - cnt[j];
                int reverse = matches(i, j) - matches(j + 1, i - 1);

                if (normal + reverse > ans || (normal + reverse == ans && (j - i < b - a || (j - i == b - a && i + 1 < a)))) {
                    ans = normal + reverse;
                    a = i + 1; b = j + 1;
                }
            }

        cout << cnt[n - 1] << " " << ans << " " << a << " " << b << "\n";
    }
}