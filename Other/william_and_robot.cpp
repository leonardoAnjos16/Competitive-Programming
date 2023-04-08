#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        heap.push(a);
        if (i & 1) heap.pop();
    }

    llong ans = 0LL;
    while (!heap.empty()) {
        ans += heap.top();
        heap.pop();
    }

    cout << ans << "\n";
}