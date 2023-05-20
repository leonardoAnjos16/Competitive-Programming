#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int l = 1, r = N, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int hits = 0, t = 0;
        map<int, int> last_used;
        set<pair<int, int>> cache;

        for (int i = 0; i < N; i++) {
            if (last_used.count(a[i])) {
                cache.erase(make_pair(last_used[a[i]], a[i]));
                cache.emplace(last_used[a[i]] = t++, a[i]);
                hits++;
            } else if ((int) cache.size() < mid) {
                last_used[a[i]] = t++;
                cache.emplace(last_used[a[i]], a[i]);
            } else {
                auto it = cache.begin();
                last_used.erase(it->second);

                cache.erase(it);
                last_used[a[i]] = t++;
                cache.emplace(last_used[a[i]], a[i]);
            }
        }

        if (hits < K) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    if (ans == -1) cout << "cbddl\n";
    else cout << ans << "\n";
}