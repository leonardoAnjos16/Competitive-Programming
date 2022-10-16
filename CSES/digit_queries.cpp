#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 18;

pair<int, llong> get_pow(llong n) {
    int idx = 1;
    llong pow = 1LL;

    while (pow * 10LL <= n) {
        idx++;
        pow *= 10LL;
    }

    return make_pair(idx, pow);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong cnt[MAX] = {0LL}, pow = 1LL;
    for (int i = 1; i < MAX; i++) {
        cnt[i] = cnt[i - 1] + 9LL * pow * i;
        pow *= 10LL;
    }

    int q; cin >> q;
    while (q--) {
        llong k; cin >> k;

        llong l = 1LL, r = 1e18, num = -1LL;
        while (l <= r) {
            llong mid = (l + r) / 2LL;

            auto [idx, p] = get_pow(mid);

            llong digits = cnt[idx - 1] + idx * (mid - p + 1LL);
            if (digits < k) l = mid + 1LL;
            else r = mid - 1LL, num = mid;
        }

        auto [idx, p] = get_pow(num);
        llong digits = cnt[idx - 1] + idx * (num - p + 1LL);

        int diff = digits - k;
        assert(diff >= 0 && diff < MAX);

        string aux = to_string(num);
        reverse(aux.begin(), aux.end());

        char ans = aux[diff];
        cout << ans << "\n";
    }
}