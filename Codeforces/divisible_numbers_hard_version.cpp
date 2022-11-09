#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
        if (!(n % i)) {
            divs.push_back(i);
            if (i * i < n)
                divs.push_back(n / i);
        }

    return divs;
}

int multiple(llong x, int l, int r) {
    // x * y > l
    // y > l / x
    int y = l / x + 1;
    if (1LL * x * y > r) return -1;
    return x * y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<int> adivs = divisors(a);
        vector<int> bdivs = divisors(b);

        bool possible = false;
        for (int adiv: adivs) {
            for (int bdiv: bdivs) {
                int x = multiple(1LL * adiv * bdiv, a, c);
                int y = multiple(1LL * a * b / adiv / bdiv, b, d);

                if (x != -1 && y != -1) {
                    cout << x << " " << y << "\n";
                    possible = true;
                    break;
                }
            }

            if (possible) break;
        }

        if (!possible) cout << "-1 -1\n";
    }
}