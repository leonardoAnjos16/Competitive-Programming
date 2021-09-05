#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("equal.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool ans = a == b || a == c || b == c;
        cout << (ans ? "YES" : "NO") << "\n";
    }
}