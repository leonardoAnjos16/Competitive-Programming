#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {

        string s; cin >> s;
        map<char, int> cnt;

        int n = s.size(), k = 2;
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;

        int l = 1, r = n / k, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            priority_queue<pair<int, char>> heap;
            for (auto p: cnt) heap.emplace(p.second, p.first);

            bool possible = true;
            for (int i = 1; i <= k && possible; i++) {
                if ((int) heap.size() < mid) possible = false;
                else {
                    vector<pair<int, char>> taken(mid);
                    for (int j = 0; j < mid; j++) {
                        auto p = heap.top(); heap.pop();
                        taken[j] = make_pair(p.first - 1, p.second);
                    }

                    for (int j = 0; j < mid; j++)
                        if (taken[j].first > 0)
                            heap.push(taken[j]);
                }
            }

            if (!possible) r = mid - 1;
            else l = mid + 1, ans = mid;
        }

        cout << ans << "\n";
    }
}