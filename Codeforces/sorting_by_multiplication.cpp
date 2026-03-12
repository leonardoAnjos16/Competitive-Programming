#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> increasing(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            increasing[i] = increasing[i + 1];
            if (a[i] >= a[i + 1]) increasing[i]++;
        }

        int decreasing = 0, begin = 0, ans = INT_MAX;
        while (begin < n) {
            ans = min(ans, decreasing + increasing[begin] - 1);

            begin++; decreasing++;
            while (begin < n && a[begin] < a[begin - 1]) begin++;
        }

        ans = min(ans, decreasing);
        cout << ans << "\n";
    }
}