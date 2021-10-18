#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, x;
vector<int> w;
vector<pair<int, long>> memo;

pair<int, long> rides_weight(int subset) {
    if (!subset) return make_pair(1, 0);

    auto &ans = memo[subset];
    if (~ans.first) return ans;

    ans = make_pair(INT_MAX, LLONG_MAX);
    for (int i = 0; i < n; i++)
        if (subset & (1 << i)) {
            auto aux = rides_weight(subset ^ (1 << i));
            if (aux.second + w[i] <= x) aux.second += w[i];
            else aux.first++, aux.second = w[i];
            ans = min(ans, aux);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    memo.assign(1 << n, make_pair(-1, -1));

    int ans = rides_weight((1 << n) - 1).first;
    cout << ans << "\n";
}