#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];

    sort(l.rbegin(), l.rend());

    int i = 0; long ans = 0LL;
    while (i + 3 < n) {
        long base = -1LL;
        while (i + 1 < n && l[i] - l[i + 1] > 1) i++;
        if (i + 1 < n) base = l[i + 1], i += 2;

        long height = -1LL;
        while (i + 1 < n && l[i] - l[i + 1] > 1) i++;
        if (i + 1 < n) height = l[i + 1], i += 2;

        if (~base && ~height) ans += base * height;
    }

    cout << ans << "\n";
}