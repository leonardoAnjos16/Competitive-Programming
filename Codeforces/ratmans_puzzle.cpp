#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n; int k;
    cin >> n >> k;

    if (n >= (1LL << k)) cout << "0\n";
    else {
        long ans = 1LL << (k - 1);
        cout << ans << "\n";
    }
}