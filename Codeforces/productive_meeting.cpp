#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        priority_queue<pair<int, int>> params;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a) params.emplace(a, i + 1);
        }

        vector<pair<int, int>> ans;
        while ((int) params.size() > 1) {
            auto p1 = params.top(); params.pop();
            auto p2 = params.top(); params.pop();

            ans.emplace_back(p1.second, p2.second);
            if (p1.first > 1) params.emplace(p1.first - 1, p1.second);
            if (p2.first > 1) params.emplace(p2.first - 1, p2.second);
        }

        int cnt = ans.size();
        cout << cnt << "\n";

        for (auto [i, j]: ans)
            cout << i << " " << j << "\n";
    }
}