#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int l = 1, r = n / k, ans = 0;
        map<int, vector<int>> coloring;

        while (l <= r) {
            int mid = (l + r) / 2;

            priority_queue<pair<int, int>> heap;
            for (auto p: cnt) heap.emplace(p.second, p.first);

            bool possible = true;
            map<int, vector<int>> curr;

            for (int i = 1; i <= k && possible; i++) {
                if ((int) heap.size() < mid) possible = false;
                else {
                    vector<pair<int, int>> taken(mid);
                    for (int j = 0; j < mid; j++) {
                        auto p = heap.top(); heap.pop();
                        curr[p.second].push_back(i);
                        taken[j] = make_pair(p.first - 1, p.second);
                    }

                    for (int j = 0; j < mid; j++)
                        if (taken[j].first > 0)
                            heap.push(taken[j]);
                }
            }

            if (!possible) r = mid - 1;
            else l = mid + 1, ans = mid, coloring = curr;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";

            if (coloring[a[i]].empty()) cout << "0";
            else {
                cout << coloring[a[i]].back();
                coloring[a[i]].pop_back();
            }
        }

        cout << "\n";
    }
}