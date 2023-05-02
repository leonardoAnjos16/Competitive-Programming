#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble INF = 1e9 + 5;

map<string, vector<pair<string, ldouble>>> g;
set<string> vis;

ldouble convert(string &unit, string &target, ldouble val, bool &found) {
    if (unit == target) {
        found = true;
        return val;
    }

    if (vis.count(unit)) return -INF;

    vis.insert(unit);
    for (auto &[nxt, c]: g[unit]) {
        ldouble ans = convert(nxt, target, val * c, found);
        if (found) return ans;
    }

    return -INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(20);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int one;
        ldouble v;
        string u1, u2, equal;

        cin >> one >> u1 >> equal >> v >> u2;

        g[u1].emplace_back(u2, v);
        g[u2].emplace_back(u1, 1.0L / v);
    }

    while (q--) {
        ldouble v;
        string u1, u2, to;

        cin >> v >> u1 >> to >> u2;

        vis.clear();
        bool found = false;
        ldouble ans = convert(u1, u2, v, found);

        if (!found) cout << "impossible\n";
        else cout << ans << "\n";
    }
}