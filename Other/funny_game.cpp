#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int primes(int x) {
    int ans = 0;
    for (int i = 2; i * i <= x; i++)
        while (!(x % i)) {
            ans++;
            x /= i;
        }

    if (x > 1) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("funny.in", "r", stdin);
    freopen("funny.out", "w", stdout);

    int w, h;
    while (cin >> w >> h, w || h)
        cout << w << " " << h << " - " << (primes(h) >= primes(w) ? "Harry" : "Vera") << "\n";
}