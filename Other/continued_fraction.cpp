#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;

        vector<int> ans;
        while (x > 1 && x % y) {
            ans.push_back(x / y);
            swap(x, y);
            y %= x;
        }

        if (x % y) {
            ans.push_back(0);
            ans.push_back(y);
        } else {
            ans.push_back(x / y - 1);
            ans.push_back(1);
        }

        int n = ans.size();
        assert(n <= 100);

        cout << (n - 1);
        for (int i = 0; i < n; i++)
            cout << " " << ans[i];

        cout << "\n";
    }
}