#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 62;

int max_power_exponent(llong n) {
    int l = 1, r = MAX, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        llong power_sum = (1LL << (mid + 1)) - 2LL;

        if (power_sum > n) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    return ans;
}

llong get_size(llong id, llong path, llong node, llong sz) {
    if (node == id) return sz;
    if (sz == 2LL) return 1LL;

    int exponent = max_power_exponent(sz - 1LL);
    llong next_power = 1LL << (exponent + 1);
    llong power_sum = next_power - 2LL;

    llong rem = sz - power_sum - 1LL;
    llong left = min(next_power >> 1, rem);
    llong right = rem - left;

    if (path & 1) return get_size(id, path >> 1, (node << 1) + 1, (power_sum >> 1) + right);
    return get_size(id, path >> 1, node << 1, (power_sum >> 1) + left);
}

llong get_path_from_root(llong id) {
    llong path = 1LL;
    while (id > 1) {
        path <<= 1;
        path |= id & 1;
        id >>= 1;
    }

    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong n, k;
    cin >> n >> k;

    int height = 0;
    llong mx_node = 1LL;

    while (height + 1 < k && mx_node < n) {
        height++;
        mx_node = min(2 * mx_node + 1, n);
    }

    llong l = 1LL, r = mx_node, ans = 0LL;
    while (l <= r) {
        llong mid = (l + r) / 2LL;
        llong sz = get_size(mid, get_path_from_root(mid), 1, n);

        if (sz - 1LL > n - k) l = mid + 1LL;
        else r = mid - 1LL, ans = mx_node - mid + 1LL;
    }

    assert(ans);
    cout << ans << "\n";
}