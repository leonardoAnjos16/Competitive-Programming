#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (n == a && a == b) cout << "Yes\n";
        else if (a + b + 2 <= n) cout << "Yes\n";
        else cout << "No\n";
    }
}