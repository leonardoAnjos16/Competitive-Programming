#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    llong fst = LLONG_MIN, snd = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        fst = max(fst, -x + 1LL * c * i);
        snd = max(snd, x + 1LL * c * i);

        llong ans = max(x - 1LL * c * i + fst, -x - 1LL * c * i + snd);

        if (i > 1) cout << " ";
        cout << ans;
    }

    cout << "\n";
}