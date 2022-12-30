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

        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            heap.push(a);
        }

        while (m--) {
            int b; cin >> b;
            heap.pop();
            heap.push(b);
        }

        llong ans = 0LL;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }

        cout << ans << "\n";
    }
}