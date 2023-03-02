#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int size = 0, nxt = l;
        while (nxt <= r) {
            size++;
            nxt <<= 1;
        }

        if (size == 1) cout << "1 " << (r - l + 1) << "\n";
        else {
            int twos = r / (1 << (size - 1)) - l + 1;
            int threes = max(r / ((1 << (size - 2)) * 3) - l + 1, 0);
            threes = (threes * (size - 1LL)) % MOD;

            int cnt = (twos + threes) % MOD;
            cout << size << " " << cnt << "\n";
        }
    }
}