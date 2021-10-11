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
    while (n--) {
        long double fa, fb;
        cin >> fa >> fb;

        int a = note(fa);
        int b = note(fb);

        ans += b - a;
    }

    ans = abs(ans);
    cout << ans << "\n";
}