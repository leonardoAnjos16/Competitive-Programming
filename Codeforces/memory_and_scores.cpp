#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k, t;
    cin >> a >> b >> k >> t;

    vector<int> coeffs(2 * k + 1);
    for (int i = 0; i <= 2 * k; i++)
        coeffs[i] = i + 1;

    for (int i = 1; i < 2 * t; i++) {
        int size = coeffs.size();
        int new_size = size + 2 * k;
        vector<int> new_coeffs(new_size);

        for (int j = 0, l = -2 * k, r = 0; j < new_size; j++, l++, r++) {
            new_coeffs[j] = (r >= size ? coeffs[size - 1] : coeffs[r]) - (l <= 0 ? 0 : coeffs[l - 1]);
            new_coeffs[j] = (new_coeffs[j] + MOD) % MOD;

            if (j) {
                new_coeffs[j] += new_coeffs[j - 1];
                new_coeffs[j] %= MOD;
            }
        }

        coeffs = new_coeffs;
    }

    long ans = 0LL;
    for (int i = b + 2 * k * t - a + 1; i <= 4 * k * t; i++)
        ans = (ans + coeffs[i] - (i ? coeffs[i - 1] : 0) + MOD) % MOD;

    cout << ans << "\n";
}