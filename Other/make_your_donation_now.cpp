#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    long long int sum = 0LL;
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        sum += a;
        events.emplace_back(a, 0);
        events.emplace_back(b, 1);
    }

    sort(events.begin(), events.end());

    int cnt = 0, chosen = 0;
    long long int ans = sum;

    for (auto [v, type]: events) {
        if (sum + 1LL * cnt * v > ans) {
            chosen = v;
            ans = sum + 1LL * cnt * v;
        }

        if (type) cnt--;
        else sum -= v, cnt++;
    }

    cout << chosen << " " << ans << "\n";
}