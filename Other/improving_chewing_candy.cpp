#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s; cin >> s;

    int eq = 0;
    while (eq < n && s[n - eq - 1] == s[0]) eq++;

    if (eq >= n) {
        cout << "-1\n";
        return 0;
    }

    s = string(eq, s[0]) + s.substr(0, n - eq);

    int idx = 0;
    vector<pair<char, int>> blocks;

    while (idx < n) {
        int cnt = 1;
        while (idx + 1 < n && s[idx + 1] == s[idx])
            cnt++, idx++;

        blocks.emplace_back(s[idx++], cnt);
    }

    n = blocks.size();

    int ans = 0, al = -1, ar = -1;
    int r = 0, sum = 0, cnt[MAX] = {0};
    bool cloying = false;

    for (int l = 0; l < n; l++) {
        while (r < n + l && !cloying) {
            auto [letter, c] = blocks[r % n];
            cnt[letter - 'a'] += c;
            sum += c;

            r++;
            if (cnt[letter - 'a'] > k) cloying = true;

            if (!cloying && sum > ans) {
                al = l;
                ar = r;
                ans = sum;
            }
        }

        auto [letter, c] = blocks[l];
        int prev = cnt[letter - 'a'];
        cnt[letter - 'a'] -= c;
        sum -= c;

        if (prev > k && cnt[letter - 'a'] <= k) cloying = false;
    }

    if (!ans) cout << "-1\n";
    else {
        cout << ans << "\n";
        for (int i = al; i < ar; i++)
            cout << string(blocks[i % n].second, blocks[i % n].first);

        cout << "\n";
    }
}