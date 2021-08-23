#include <bits/stdc++.h>

using namespace std;

#define long long long int

long sum(long b) {
    long ans = (b + 1) * (b + 2) / 2;

    long aux = (b + 1) / 2;
    ans -= aux * (aux + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long k; cin >> k;

        long l = 0, r = 1e9, col;
        while (l <= r) {
            long mid = (l + r) / 2;

            long odd = 2 * mid + 1;
            long aux = sum(odd) - odd + 1;

            if (aux > k) r = mid - 1;
            else l = mid + 1, col = mid;
        }

        long odd = 2 * col + 1;
        long fst = sum(odd) - odd + 1;
        long mid = fst + col;

        long row = k >= mid ? col : k - fst;
        if (k >= mid) col -= k - mid;

        row++; col++;
        cout << row << " " << col << "\n";
    }
}