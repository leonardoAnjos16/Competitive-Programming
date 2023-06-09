#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    set<llong> all, suffix;
    for (int i = 0; i < n; i++) {
        llong a; cin >> a;

        set<llong> nsuffix;
        for (llong g: suffix)
            nsuffix.insert(gcd(g, a));

        nsuffix.insert(a);
        suffix = nsuffix;

        for (llong g: suffix)
            all.insert(g);
    }

    int ans = all.size();
    cout << ans << "\n";
}