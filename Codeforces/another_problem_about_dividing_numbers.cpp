#include <bits/stdc++.h>

using namespace std;

#define long long long int

map<int, int> memo;

int prime_factors(int n) {
    if (n == 1) return 0;

    if (memo.count(n))
        return memo[n];

    int ans = 0, aux = n;
    for (int i = 2; i * i <= aux; i++)
        while (!(aux % i)) ans++, aux /= i;

    if (aux > 1) ans++;
    return memo[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        if (a > b) swap(a, b);
        int mx = prime_factors(a) + prime_factors(b);

        if (k == 1 && a < b && !(b % a)) cout << "YES\n";
        else if (k > 1 && k <= mx) cout << "YES\n";
        else cout << "NO\n";
    }
}