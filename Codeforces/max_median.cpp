#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        bool possible = false;
        vector<int> ps(n + 1, 0);

        int mn = INT_MAX;
        for (int i = 0; i < n && !possible; i++) {
            ps[i + 1] = ps[i] + (a[i] < mid ? -1 : 1);
            if (i + 1 >= k) mn = min(mn, ps[i - k + 1]);
            if (mn < ps[i + 1]) possible = true;
        }

        if (!possible) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    cout << ans << "\n";
}