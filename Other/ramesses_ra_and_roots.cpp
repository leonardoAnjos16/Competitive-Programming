#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> r(q);
    for (int i = 0; i < q; i++)
        cin >> r[i];

    int ones = 0;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) ones++;
        else {
            int g = 0, aux = a[i];
            for (int j = 2; j * j <= aux; j++) {
                int exp = 0;
                while (!(aux % j))
                    exp++, aux /= j;

                g = gcd(g, exp);
            }

            if (aux > 1) g = 1;

            for (int j = 1; j * j <= g; j++)
                if (!(g % j)) {
                    cnt[j]++;
                    if (j * j < g)
                        cnt[g / j]++;
                }
        }
    }

    for (int i = 0; i < q; i++) {
        int ans = ones + cnt[r[i]];
        cout << ans << "\n";
    }
}