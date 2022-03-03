#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int idx = n - 2, k = 1, ans = 0;
        while (idx >= 0) {
            while (idx >= 0 && a[idx] == a[idx + 1]) idx--, k++;
            if (idx < 0) break;

            int cnt = 0;
            while (idx >= 0 && cnt < k)
                a[idx] = a[idx + 1], idx--, cnt++;

            ans++;
            k *= 2;
        }

        cout << ans << "\n";
    }
}