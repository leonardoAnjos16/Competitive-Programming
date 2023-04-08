#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int ans = INT_MAX;
        for (int i = 1; i < MAX; i++)
            ans = min(ans, i + a / i + b / i + (a % i ? 1 : 0) + (b % i ? 1 : 0) - 1);

        cout << ans << "\n";
    }
}