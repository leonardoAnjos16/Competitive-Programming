#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector< pair<int, int> > juices(n);
    for (int i = 0; i < n; i++) {
        int c; string s;
        cin >> c >> s;

        int mask = 0;
        for (int j = 0; j < (int) s.size(); j++)
            mask |= 1 << (s[j] - 'A');

        juices[i] = {c, mask};
    }

    vector<int> mn(4, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            if (juices[i].second == 1 << j)
                mn[j] = min(mn[j], juices[i].first);

        if (juices[i].second == (1 << 3) - 1)
            mn[3] = min(mn[3], juices[i].first);
    }

    int ans = min(mn[0] + mn[1] + mn[2], mn[3]);
    for (int i = 0; i < (int) juices.size(); i++)
        for (int j = i + 1; j < (int) juices.size(); j++)
            if ((juices[i].second | juices[j].second) == (1 << 3) - 1)
                ans = min(ans, juices[i].first + juices[j].first);

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}