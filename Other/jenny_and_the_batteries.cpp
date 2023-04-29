#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; llong K;
    cin >> N >> K;

    int mx = INT_MIN;
    vector<int> a(N), b(N), c(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mx = max(mx, a[i]);
    }

    int l = 0, r = mx, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int i = 0; i < N; i++)
            if (a[i] < mid)
                heap.emplace(c[i], mid - a[i]);

        bool possible = true;
        llong total_cost = 0LL;

        for (int i = 0; i < N && possible; i++)
            if (a[i] > mid) {
                int diff = a[i] - mid;
                while (!heap.empty() && diff) {
                    auto [cost, available] = heap.top();
                    heap.pop();

                    int aux = min(available, diff);
                    available -= aux;
                    diff -= aux;

                    total_cost += 1LL * b[i] * aux;
                    total_cost += 1LL * cost * aux;

                    if (available)
                        heap.emplace(cost, available);
                }

                if (diff || total_cost > K)
                    possible = false;
            }

        if (!possible) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}