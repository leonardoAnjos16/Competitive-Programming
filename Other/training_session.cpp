#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<pair<int, int>, int> cab;
    int ca[MAX] = {0}, cb[MAX] = {0};

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        ca[a]++;
        cb[b]++;
        cab[make_pair(a, b)]++;
    }

    llong ans = n * (n - 1LL) * (n - 2LL) / 6LL;
    for (auto [ab, cnt]: cab) {
        auto [a, b] = ab;
        ans -= cnt * (cnt - 1LL) * (cnt - 2LL) / 6LL;
        ans -= cnt * (cnt - 1LL) / 2LL * (n - cnt);
        ans -= 1LL * cnt * (ca[a] - cnt) * (cb[b] - cnt);
    }

    cout << ans << "\n";
}