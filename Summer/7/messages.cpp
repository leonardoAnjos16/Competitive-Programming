#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> m(n), k(m);
    for (int i = 0; i < n; i++)
        cin >> m[i] >> k[i];

    vector<int> chosen;
    int ans = 0, best = INT_MIN;

    for (int t = 1; t <= 20; t++) {
        int sum[MAX] = {0};
        for (int i = 0; i < n; i++) {
            if (k[i] >= t) sum[m[i]] += t;
            else sum[m[i]] += k[i];
        }

        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < n; i++) {
            if (sum[m[i]] != -1)
                heap.emplace(sum[m[i]], m[i]);

            sum[m[i]] = -1;
        }

        if ((int) heap.size() < t) break;

        int expected = 0;
        vector<int> messages;

        for (int i = 0; i < t; i++) {
            expected += heap.top().first;
            messages.push_back(heap.top().second);
            heap.pop();
        }

        if (expected * ans > best * t) {
            ans = t;
            best = expected;
            chosen = messages;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        if (i) cout << " ";
        cout << chosen[i];
    }

    cout << "\n";
}