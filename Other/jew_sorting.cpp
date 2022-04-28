#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int operations(int l, int r) {
    if (l == r) return 0;

    bool non_decreasing = true;
    for (int i = l + 1; i <= r && non_decreasing; i++)
        if (a[i] < a[i - 1]) non_decreasing = false;

    if (non_decreasing) return 0;

    int m = (l + r) / 2;
    return min(operations(l, m), operations(m + 1, r)) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    a.resize(1 << n);
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];

    int ans = operations(0, (1 << n) - 1);
    cout << ans << "\n";
}