#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> researchers(n);
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        researchers[i] = make_pair(a, s);
    }

    sort(researchers.begin(), researchers.end());

    multiset<int> occuppied;
    priority_queue<int, vector<int>, greater<int>> available;

    int unlocks = 0;
    for (auto [a, s]: researchers) {
        auto end = occuppied.upper_bound(a);
        for (auto it = occuppied.begin(); it != end; it++)
            available.push(*it);

        occuppied.erase(occuppied.begin(), end);

        while (!available.empty() && a - available.top() > m)
            available.pop();

        if (available.empty()) unlocks++;
        else available.pop();

        occuppied.insert(a + s);
    }

    int ans = n - unlocks;
    cout << ans << "\n";
}