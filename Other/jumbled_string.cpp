#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int count(int subseqs) {
    int l = 0, r = subseqs + 10, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * (mid - 1LL) / 2LL < subseqs) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    if (ans != -1 && ans * (ans - 1LL) / 2LL > subseqs)
        return -1;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int zeros = count(a);
    int ones = count(d);

    if (zeros == -1 || ones == -1) {
        cout << "impossible\n";
        return 0;
    }

    if (!zeros) zeros += (b || c);
    if (!ones) ones += (b || c);

    if (!zeros && !ones) cout << "0\n";
    else if (!zeros) cout << string(ones, '1') << "\n";
    else {
        int n = zeros + ones;
        if (1LL * a + b + c + d != n * (n - 1LL) / 2LL) cout << "impossible\n";
        else {
            int before = c / zeros;
            if (before + (c % zeros ? 1 : 0) > ones) cout << "impossible\n";
            else {
                string ans(before, '1');
                for (int i = 0; i < zeros - (c % zeros); i++)
                    ans += '0';

                if (c % zeros) ans += '1';
                for (int i = 0; i < c % zeros; i++)
                    ans += '0';

                for (int i = 0; i < ones - before - (c % zeros ? 1 : 0); i++)
                    ans += '1';

                cout << ans << "\n";
            }
        }
    }
}