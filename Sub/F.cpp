#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<llong, llong> cfrac(int n) {
    if (!n) return make_pair(1LL, 1LL);

    auto [num, den] = cfrac(n - 1);

    llong nnum = den + num;
    llong nden = den;
    swap(nnum, nden);

    llong g = gcd(nnum, nden);
    nnum /= g; nden /= g;

    return make_pair(nnum, nden);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    auto [ans, _] = cfrac(N);
    cout << ans << "\n";
}