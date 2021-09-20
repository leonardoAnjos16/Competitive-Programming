#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first > b.first) return true;
    return a.first == b.first && a.second < b.second;
}

struct Comp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return comp(b, a);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<pair<int, int>, Comp> front;
    vector<pair<int, int>> teams(n, make_pair(0, 0));

    while (m--) {
        int t, p;
        cin >> t >> p;

        auto old = teams[--t];
        teams[t].first++;
        teams[t].second += p;

        if (!t) front.erase(front.begin(), front.upper_bound(teams[0]));
        else if (!comp(old, teams[0]) && comp(teams[t], teams[0])) front.insert(teams[t]);
        else if (comp(old, teams[0])) {
            auto it = front.find(old);
            front.erase(it);
            front.insert(teams[t]);
        }

        int ans = front.size() + 1;
        cout << ans << "\n";
    }
}