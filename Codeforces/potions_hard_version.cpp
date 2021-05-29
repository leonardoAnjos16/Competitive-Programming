#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long sum = 0LL; int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] >= 0LL) {
            ans++;
            sum += a[i];
            pq.push(a[i]);
        } else if (!pq.empty() && pq.top() < a[i]) {
            sum -= pq.top();
            pq.pop();
            pq.push(a[i]);
            sum += a[i];
        }
    }

    cout << ans << "\n";
}