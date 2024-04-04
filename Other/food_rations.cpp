#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
const int MOD = 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string best[MOD];
    string num = "1689";

    do best[stoi(num) % MOD] = num;
    while (next_permutation(num.begin(), num.end()));

    string s; cin >> s;
    int n = s.size();

    int cnt[MAX] = {0};
    for (int i = 0; i < n; i++)
        cnt[s[i] - '0']++;

    assert(cnt[1] && cnt[6] && cnt[8] && cnt[9]);

    if (cnt[0] + cnt[1] + cnt[6] + cnt[8] + cnt[9] == n) {
        string ans = best[0] + string(cnt[0], '0');
        cout << ans << "\n";
    } else {
        string ans = "";
        for (int i = MAX - 1; i >= 0; i--) {
            int use = cnt[i] - (i == 1 || i == 6 || i == 8 || i == 9 ? 1 : 0);
            ans += string(use, '0' + i);
        }

        int rem = 0;
        for (char c: ans) {
            rem *= 10;
            rem += c - '0';
            rem %= MOD;
        }

        rem *= 10000;
        rem %= MOD;

        ans += best[(MOD - rem) % MOD];
        cout << ans << "\n";
    }
}