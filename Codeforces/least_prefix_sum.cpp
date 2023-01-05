#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<llong> ps(n + 1, 0LL);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i];

        int ans = 0;
        llong sum = 0LL;
        priority_queue<int> mx;

        for (int i = m; i > 0; i--) {
            while (ps[i] < ps[m]) {
                assert(!mx.empty());
                ps[m] -= 2LL * mx.top();
                sum -= 2LL * mx.top();
                mx.pop();
                ans++;
            }

            mx.push(a[i]);
        }

        priority_queue<int, vector<int>, greater<int>> mn;
        for (int i = m + 1; i <= n; i++) {
            mn.push(a[i]);
            while (ps[i] + sum < ps[m]) {
                assert(!mn.empty());
                ps[i] -= 2LL * mn.top();
                sum -= 2LL * mn.top();
                mn.pop();
                ans++;
            }
        }

        cout << ans << "\n";
    }
}