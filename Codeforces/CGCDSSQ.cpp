#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<map<int, int>> cnt(n + 1, map<int, int>());
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;

        cnt[i][a] = 1;
        for (auto [g, c]: cnt[i - 1])
            cnt[i][gcd(g, a)] += c;
    }

    map<int, llong> ans;
    for (int i = 1; i <= n; i++)
        for (auto [g, c]: cnt[i])
            ans[g] += c;

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << "\n";
    }
}