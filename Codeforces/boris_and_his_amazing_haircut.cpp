#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        stack<int> razors;
        map<int, int> cnt;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            if (a[i] < b[i]) possible = false;
            else {
                while (!razors.empty() && razors.top() < b[i]) razors.pop();
                if (a[i] == b[i] || (!razors.empty() && razors.top() == b[i])) continue;
                razors.push(b[i]);
                cnt[b[i]]++;
            }
        }

        int m; cin >> m;
        while (m--) {
            int x; cin >> x;
            cnt[x]--;
        }

        for (auto [razor, c]: cnt)
            if (c > 0) possible = false;

        if (!possible) cout << "NO\n";
        else cout << "YES\n";
    }
}