#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> l(n);
        for (int i = 0; i < n; i++)
            cin >> l[i];

        int ans = -1;
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (l[j] > i) cnt++;

            if (cnt == i) ans = i;
        }

        cout << ans << "\n";
    }
}