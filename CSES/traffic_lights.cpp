#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<pair<int, int>> passages;
    passages.emplace(x, 0);

    map<int, int> lengths;
    lengths[x] = 1;

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        int p; cin >> p;

        auto it = passages.lower_bound(make_pair(p, 0));
        assert(it != passages.end());

        auto [r, l] = *it;
        if (--lengths[r - l] == 0)
            lengths.erase(r - l);

        lengths[p - l]++;
        lengths[r - p]++;

        passages.erase(it);
        passages.emplace(p, l);
        passages.emplace(r, p);

        int ans = lengths.rbegin()->first;
        cout << ans;
    }
}