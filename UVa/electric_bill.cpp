#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long X = 2LL * 100, Y = 3LL * 9900, Z = 5LL * 990000;

long get_bill(long CWh) {
    long bill = 2 * min(X / 2, CWh); CWh -= X / 2;
    if (CWh > 0) bill += 3 * min(Y / 3, CWh), CWh -= Y / 3;
    if (CWh > 0) bill += 5 * min(Z / 5, CWh), CWh -= Z / 5;
    if (CWh > 0) bill += 7 * CWh;

    return bill;
}

int main() {
    long A, B;
    while (scanf("%lld %lld", &A, &B), A | B) {
        long l = 0, r = A, CWh;
        while (l <= r) {
            CWh = (l + r) / 2;

            long bill = get_bill(CWh);

            if (bill == A) break;
            else if (bill < A) l = CWh + 1;
            else r = CWh - 1;
        }

        long ans = -1;
        l = 0; r = CWh / 2;

        while (l <= r) {
            long mid = (l + r) / 2;

            long x = get_bill(mid);
            long y = get_bill(CWh - mid);

            long diff = y - x;

            if (diff == B) ans = x, l = r + 1;
            else if (diff > B) l = mid + 1;
            else r = mid - 1;
        }

        printf("%lld\n", ans);
    }
}