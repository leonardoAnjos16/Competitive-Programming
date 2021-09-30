#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        deque<int> ans;
        ans.push_back(p[0]);

        for (int i = 1; i < n; i++) {
            if (p[i] < ans.front()) ans.push_front(p[i]);
            else ans.push_back(p[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans.front();
            ans.pop_front();
        }

        cout << "\n";
    }
}