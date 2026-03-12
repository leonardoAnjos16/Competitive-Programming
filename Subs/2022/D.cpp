#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int N;

int dist(int x, int y) {
    int ans = 0;
    while (x != (1 << (N - 1)) || y != (1 << (N - 1))) {
        ans++;

        if (x & (1 << (N - 1))) x ^= (1 << (N - 1));
        x <<= 1;

        if (y & (1 << (N - 1))) y ^= (1 << (N - 1));
        y <<= 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int x, y;
    cin >> x >> y;

    int ans = dist(x, y);
    cout << ans << "\n";
}