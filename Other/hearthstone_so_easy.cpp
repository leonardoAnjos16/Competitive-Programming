#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n == 1) cout << "freesin\n";
        else if (n <= k + 1) cout << "pllj\n";
        else cout << "freesin\n";
    }
}