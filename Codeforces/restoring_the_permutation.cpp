#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int, int> pos;
        for (int i = 0; i < n; i++) {
            int q; cin >> q;
            if (!pos.count(q))
                pos[q] = i;
        }

        vector<int> mn_p(n, 0);
        vector<int> mx_p(n, 0);

        for (auto pr: pos) {
            mn_p[pr.second] = pr.first;
            mx_p[pr.second] = pr.first;
        }

        vector<int> missing;
        for (int i = 1; i <= n; i++)
            if (!pos.count(i))
                missing.push_back(i);

        int idx = 0;
        for (int i = 0; i < n; i++)
            if (!mn_p[i]) mn_p[i] = missing[idx++];

        idx = 0;
        auto mx = pos.begin();
        priority_queue<int> curr;

        while (mx != pos.end()) {
            while (idx < (int) missing.size() && missing[idx] <= mx->first)
                curr.push(missing[idx++]);

            for (int i = mx->second + 1; i < n && !mx_p[i]; i++)
                mx_p[i] = curr.top(), curr.pop();

            mx++;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << mn_p[i];
        }

        cout << "\n";

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << mx_p[i];
        }

        cout << "\n";
    }
}