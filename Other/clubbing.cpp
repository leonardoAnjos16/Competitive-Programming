#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    bool seen[1 << MAX] = {0};
    for (int i = 0; i < N; i++) {
        string club;
        cin >> club;

        int mask = 0;
        for (char c: club)
            mask |= 1 << (c - 'a');

        seen[mask] = true;
    }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < (1 << MAX); j++)
            if (j & (1 << i))
                seen[j] |= seen[j ^ (1 << i)];

    string schedule;
    cin >> schedule;

    llong ans = 0LL;
    int l = 0, r = 0, mask = 1 << (schedule[0] - 'a');

    int cnt[MAX] = {0};
    cnt[schedule[0] - 'a']++;

    while (l < (int) schedule.size()) {
        while (r + 1 < (int) schedule.size() && !seen[mask]) {
            mask |= 1 << (schedule[++r] - 'a');
            cnt[schedule[r] - 'a']++;
        }

        if (seen[mask]) ans += (int) schedule.size() - r;
        if (--cnt[schedule[l] - 'a'] == 0) mask ^= 1 << (schedule[l] - 'a');

        l++;
    }

    cout << ans << "\n";
}