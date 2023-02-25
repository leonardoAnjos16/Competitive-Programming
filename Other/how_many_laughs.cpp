#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong my_lcm(llong a, llong b) {
    if (!a) return b;
    if (!b) return a;
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    llong ans = 0LL;
    for (int i = 1; i < (1 << N); i++) {
        llong m = 0;
        for (int j = 0; j < N && m <= X; j++)
            if (i & (1 << j)) m = my_lcm(m, a[j]);

        if (__builtin_popcount(i) & 1) ans += X / m;
        else ans -= X / m;
    }

    cout << ans << "\n";
}