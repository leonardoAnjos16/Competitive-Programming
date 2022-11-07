#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    sort(h.begin(), h.end());

    multiset<pair<int, int>> prices;
    for (int i = 0; i < n; i++) {
        int prev = !i ? 0 : h[i - 1];
        prices.emplace(h[i], prev);
    }

    while (m--) {
        int t; cin >> t;

        auto it = prices.upper_bound(make_pair(t, INT_MAX));
        if (it == prices.end()) {
            if (prices.empty()) cout << "-1\n";
            else {
                cout << prices.rbegin()->first << "\n";
                prices.erase(prices.find(*prices.rbegin()));
            }
        }
        else if (!it->second) cout << "-1\n";
        else {
            cout << it->second << "\n";

            pair<int, int> aux = make_pair(it->second, it->second);
            if (prices.find(aux) != prices.end()) prices.erase(prices.find(aux));
            else {
                aux = *it;
                it = prices.lower_bound(make_pair(it->second, 0));
                int prev = it->second;
                prices.erase(it);

                prices.erase(prices.find(aux));
                aux.second = prev;
                prices.insert(aux);
            }
        }
    }
}