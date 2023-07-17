#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int count_digits(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int digits = count_digits(n);
    int ans = 10 * (digits - 1);

    if (digits < 10)
        for (int i = 1; i < 10; i++) {
            string num(digits, '0' + i);
            if (stoi(num) <= n) ans++;
        }

    if (n < 10) ans++;
    cout << ans << "\n";
}