#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        priority_queue<pair<int, int>> heap;
        for (auto p: cnt)
            heap.emplace(p.second, p.first);

        int ans = n;
        while ((int) heap.size() > 1) {
            auto p1 = heap.top(); heap.pop();
            auto p2 = heap.top(); heap.pop();

            ans -= 2;
            if (p1.first > 1) heap.emplace(p1.first - 1, p1.second);
            if (p2.first > 1) heap.emplace(p2.first - 1, p2.second);
        }

        assert(ans >= 0);
        cout << ans << "\n";
    }
}