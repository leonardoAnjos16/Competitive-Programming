#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> nps(n + 1);
        for (int i = 0; i <= n; i++)
            nps[i] = i;

        for (int i = 1; i <= n && k; i++)
            for (int j = 1; j <= n - i && k; j++, k--)
                swap(nps[j], nps[j + 1]);

        int idx = n;
        while (k--) {
            nps[idx] = -nps[idx];
            idx--;
        }

        reverse(nps.begin() + idx + 1, nps.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = -nps[i + 1] + nps[i];

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}