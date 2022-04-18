#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    priority_queue<int> heap;
    while (n--) {
        int h; cin >> h;
        heap.push(h);
    }

    int ans = INT_MAX, cnt = 0;
    while (!heap.empty()) {
        ans = min(ans, cnt + heap.top());
        heap.pop();
        cnt++;
    }

    ans = min(ans, cnt);
    cout << ans << "\n";
}