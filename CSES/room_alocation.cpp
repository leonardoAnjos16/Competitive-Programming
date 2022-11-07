#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        events.emplace_back(a, 0, i);
        events.emplace_back(b, 1, i);
    }

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> available;
    for (int i = 0; i < n; i++)
        available.push(i + 1);

    int ans = 1;
    vector<int> room(n);

    for (auto [time, type, idx]: events) {
        if (type) available.push(room[idx]);
        else {
            room[idx] = available.top();
            available.pop();

            ans = max(ans, n - (int) available.size());
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << room[i];
    }

    cout << "\n";
}