#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, k;
vector<int> a;
vector<pair<int, long>> memo;

pair<int, long> times_volume(int used = 0) {
    if (used == (1 << n) - 1) return make_pair(1, 0LL);

    auto &ans = memo[used];
    if (~ans.first) return ans;

    ans = make_pair(INT_MAX, LLONG_MAX);
    for (int i = 0; i < n; i++)
        if (!(used & (1 << i))) {
            auto aux = times_volume(used ^ (1 << i));
            if (aux.second + a[i] <= k) aux.second += a[i];
            else aux.first++, aux.second = a[i];
            ans = min(ans, aux);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memo.assign(1 << n, make_pair(-1, -1LL));

    int ans = times_volume().first;
    cout << ans << "\n";
}