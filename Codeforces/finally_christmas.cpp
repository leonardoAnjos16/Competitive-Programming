#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<tuple<int, int, int>> events;
    for (int i = 0; i < N; i++) {
        int L, R, H;
        cin >> L >> R >> H;

        events.emplace_back(L, H, 0);
        events.emplace_back(R, H, 1);
    }

    sort(events.begin(), events.end());

    int curr = 0;
    multiset<int> heights;
    heights.insert(0);

    long ans = 0LL;
    for (auto [x, y, type]: events) {
        long highest = *heights.rbegin();
        ans += highest * (x - curr);
        curr = x;

        if (!type) heights.insert(y);
        else {
            auto it = heights.lower_bound(y);
            heights.erase(it);
        }
    }

    cout << ans << "\n";
}