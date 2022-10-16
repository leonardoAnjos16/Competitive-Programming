#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int count(int base, int n) {
    int cnt = 0;
    long long int pow = base;

    while (pow <= n) {
        cnt += n / pow;
        pow *= base;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = count(5, n);
    cout << ans << "\n";
}