#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long D, d, P, Q;
        cin >> D >> d >> P >> Q;

        long ans = D * P;

        long aux = D / d;
        long sum = aux * (aux - 1) / 2LL;
        ans += d * Q * sum;

        ans += aux * Q * (D % d);
        cout << ans << "\n";
    }
}