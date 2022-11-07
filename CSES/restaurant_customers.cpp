#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        events.emplace_back(a, 1);
        events.emplace_back(b, -1);
    }

    sort(events.begin(), events.end());

    int ans = 0, customers = 0;
    for (auto [time, type]: events) {
        customers += type;
        ans = max(ans, customers);
    }

    cout << ans << "\n";
}