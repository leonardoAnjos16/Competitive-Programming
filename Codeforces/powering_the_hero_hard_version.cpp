#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong ans = 0LL;
        priority_queue<int> heap;

        for (int i = 0; i < n; i++) {
            int s; cin >> s;
            if (s) heap.push(s);
            else if (!heap.empty()) {
                ans += heap.top();
                heap.pop();
            }
        }

        cout << ans << "\n";
    }
}