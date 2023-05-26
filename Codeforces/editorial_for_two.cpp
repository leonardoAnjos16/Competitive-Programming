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

        vector<int> a(n);
        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        llong l = 0LL, r = 1e18, ans = -1LL;
        while (l <= r) {
            llong mid = (l + r) / 2LL;

            llong sum = 0LL;
            priority_queue<int> heap;

            vector<int> lcnt(n + 1, 0);
            for (int i = 0; i < n; i++) {
                if (sum + a[i] <= mid) {
                    sum += a[i];
                    heap.push(a[i]);
                } else if (!heap.empty() && heap.top() > a[i]) {
                    sum -= heap.top();
                    sum += a[i];

                    heap.push(a[i]);
                    heap.pop();
                }

                lcnt[i + 1] = heap.size();
            }

            sum = 0LL;
            while (!heap.empty())
                heap.pop();

            vector<int> rcnt(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                if (sum + a[i] <= mid) {
                    sum += a[i];
                    heap.push(a[i]);
                } else if (!heap.empty() && heap.top() > a[i]) {
                    sum -= heap.top();
                    sum += a[i];

                    heap.push(a[i]);
                    heap.pop();
                }

                rcnt[n - i] = heap.size();
            }

            bool possible = false;
            for (int i = 0; i <= n && !possible; i++)
                if (lcnt[i] + rcnt[n - i] >= k)
                    possible = true;

            if (!possible) l = mid + 1LL;
            else r = mid - 1LL, ans = mid;
        }

        cout << ans << "\n";
    }
}