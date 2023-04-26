#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> l(n);
        for (int i = 0; i < n; i++)
            cin >> l[i];

        vector<int> r(n);
        for (int i = 0; i < n; i++)
            cin >> r[i];

        llong sum = 0LL, ans = LLONG_MAX;
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < n; i++) {
            int size = r[i] - l[i] + 1;
            heap.push(size);
            sum += size;

            while (!heap.empty() && sum >= k) {
                ans = min(ans, r[i] + 2LL * (int) heap.size() - (sum - k));
                sum -= heap.top(); heap.pop();
            }
        }

        if (ans >= LLONG_MAX) cout << "-1\n";
        else cout << ans << "\n";
    }
}