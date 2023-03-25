#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> possible;
    for (int i = 1; i * i < MAX; i++) {
        // k * (k + 1) / 2 = i * i - 1
        // k * (k + 1) = 2 * i * i - 2

        int l = 0, r = i * i, k = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid * (mid + 1LL) < 2LL * i * i - 2LL) l = mid + 1;
            else r = mid - 1, k = mid;
        }

        if (k != -1 && k * (k + 1LL) == 2LL * i * i - 2LL)
            possible.push_back(i * i);
    }

    int a, b, t = 1;
    while (cin >> a >> b, a || b) {
        int ans = 0;
        for (int x: possible)
            if (x > a && x < b)
                ans++;

        cout << "Case " << t++ << ": " << ans << "\n";
    }
}