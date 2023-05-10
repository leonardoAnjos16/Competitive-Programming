#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong MAX = 1e11 + 5;

int sqrt(llong x) {
    int l = 1, r = 1e6, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (1LL * mid * mid > x) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    return ans;
}

bool reverse_square(llong x) {
    if (!(x % 10LL)) return false;

    llong rx = 0LL;
    while (x) {
        rx *= 10LL;
        rx += x % 10LL;
        x /= 10LL;
    }

    int srx = sqrt(rx);
    if (1LL * srx * srx < rx)
        return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<llong> squares;
    for (int i = 1; 1LL * i * i < MAX; i++)
        if (reverse_square(1LL * i * i))
            squares.push_back(1LL * i * i);

    llong A, B;
    cin >> A >> B;

    int ans = upper_bound(squares.begin(), squares.end(), B) - lower_bound(squares.begin(), squares.end(), A);
    cout << ans << "\n";
}