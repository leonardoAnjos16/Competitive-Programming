#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ans = max(ans, a);
    }

    cout << ans << "\n";
}