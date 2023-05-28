#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e8 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    int max_weight = INT_MIN;
    vector<tuple<int, int, int>> frogs(n);

    for (int i = 0; i < n; i++) {
        int l, w, h;
        cin >> l >> w >> h;

        frogs[i] = make_tuple(w, l, h);
        max_weight = max(max_weight, w);
    }

    sort(frogs.rbegin(), frogs.rend());

    int ans = 0;
    vector<int> max_height(max_weight + 1, 0LL);

    for (auto [w, l, h]: frogs) {
        ans += max_height[w] + l > d;
        for (int i = 0; i < w; i++) {
            int aux = w + i <= max_weight ? max_height[w + i] : 0;
            max_height[i] = max(max_height[i], min(aux + h, INF));
        }
    }

    cout << ans << "\n";
}