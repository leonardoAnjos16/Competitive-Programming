#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    llong ans = 0LL;
    int zeros = 1, ones = 0, accum = 0;

    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        accum ^= b;

        if (!accum) ans += ones, zeros++;
        else ans += zeros, ones++;
    }

    cout << ans << "\n";
}