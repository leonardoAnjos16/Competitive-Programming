#include <bits/stdc++.h>

using namespace std;

const long double F = 440.0;

int note(long double f) {
    return round(12 * log2(f / F));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    vector<int> fa(n), fb(n);

    for (int i = 0; i < n; i++) {
        long double fai, fbi;
        cin >> fai >> fbi;

        fa[i] = note(fai);
        fb[i] = note(fbi);
        ans += fb[i] - fa[i];
    }

    ans = abs(ans);
    for (int i = -1000; i <= 1000; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++)
            curr += fb[j] - (fa[j] + i);

        ans = min(ans, abs(curr));
    }

    cout << ans << "\n";
}