#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define LEFT 0
#define RIGHT 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        events.push_back(make_pair(l, LEFT));
        events.push_back(make_pair(r, RIGHT));
    }

    sort(events.rbegin(), events.rend());

    int ans = 0;
    for (int i = 0; i < 2 * n && events[i].second; i++) ans++;
    cout << ans << "\n";
}