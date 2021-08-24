#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 15746;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    if (N <= 2) cout << N << "\n";
    else {
        int a = 1, b = 2; N--;
        while (N--) {
            int c = (a + b) % MOD;
            a = b; b = c;
        }

        cout << a << "\n";
    }
}