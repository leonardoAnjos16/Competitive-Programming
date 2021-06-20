#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        sort(h.begin(), h.end());

        int j = 0;
        for (int i = 2; i < n; i++)
            if (h[i] - h[i - 1] < h[j + 1] - h[j])
                j = i - 1;

        vector<int> ans(n);
        ans[0] = h[j];
        ans[n - 1] = h[j + 1];

        int idx = 1;
        for (int i = j + 2; i < n; i++)
            ans[idx++] = h[i];

        for (int i = 0; i < j; i++)
            ans[idx++] = h[i];

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}