#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;

        int mid = (n + 1) / 2;
        int rem = n - mid + 1;

        int ans = s / rem;
        cout << ans << "\n";
    }
}