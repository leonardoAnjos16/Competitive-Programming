#include <bits/stdc++.h>

using namespace std;

#define long long long int

int get_bit(long n, int i) {
    return n & (1LL << i) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long X, Y, Z;
    while (cin >> X >> Y >> Z) {
        bool possible = true;
        long A = 0LL, B = 0LL;

        for (int i = 60; i >= 0 && possible; i--) {
            int or_bit = get_bit(X, i);
            int xor_bit = get_bit(Y, i);
            int and_bit = get_bit(Z, i);

            int A_bit = -1, B_bit = -1;
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= 1; k++)
                    if ((j | k) == or_bit && (j ^ k) == xor_bit && (j & k) == and_bit)
                        A_bit = j, B_bit = k;

            if (A_bit == -1) possible = false;
            else {
                if (A_bit) A |= (1LL << i);
                if (B_bit) B |= (1LL << i);
            }
        }

        if (!possible) cout << "-1\n";
        else cout << A << " " << B << "\n";
    }
}