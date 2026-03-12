#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int mx_value[MAX] = {0};
    for (int i = 0; i < n; i++) {
        string s; int v;
        cin >> s >> v;

        int sz = s.size();
        mx_value[sz] = max(mx_value[sz], v);
    }

    vector<pair<int, int>> songs;
    for (int i = 0; i < MAX; i++)
        if (mx_value[i])
            songs.emplace_back(i, mx_value[i]);

    vector<llong> last(m + 1, 0LL);
    for (int i = 0; i < (int) songs.size(); i++) {
        vector<llong> curr(m + 1, 0LL);
        for (int j = 1; j <= m; j++) {
            curr[j] = last[j];
            if (songs[i].first <= j)
                curr[j] = max(curr[j], curr[j - songs[i].first] + songs[i].second);
        }

        last = curr;
    }

    llong ans = last[m];
    cout << ans << "\n";
}