#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    if (N <= 2) cout << N << "\n";
    else {
        int a = 1, b = 1, c = 2;
        while (N--) {
            int d = (2 * c + a) % MOD;
            a = b; b = c; c = d;
        }

        cout << a << "\n";
    }
}