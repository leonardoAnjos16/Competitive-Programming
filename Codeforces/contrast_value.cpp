#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int last = -1;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int v; cin >> v;
            if (v != last) a.push_back(v);
            last = v;
        }

        n = a.size();

        int ans = 1;
        for (int i = 1; i + 1 < n; i++)
            if ((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1]))
                ans++;

        if (n > 1) ans++;
        cout << ans << "\n";
    }
}