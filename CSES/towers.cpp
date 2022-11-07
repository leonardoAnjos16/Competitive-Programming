#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;

        auto it = towers.upper_bound(k);
        if (it != towers.end()) towers.erase(it);
        towers.insert(k);
    }

    int ans = towers.size();
    cout << ans << "\n";
}