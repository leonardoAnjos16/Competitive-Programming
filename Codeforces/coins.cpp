#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong n, k;
        cin >> n >> k;

        llong diff = n - k;
        if (!(diff & 1LL)) cout << "YES\n";
        else if (!(n & 1LL)) cout << "YES\n";
        else cout << "NO\n";
    }
}