#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int mx = INT_MIN, ans = 0;
    for (int i = 0; i < n; i++) {
        int A; cin >> A;
        if (A > mx) {
            ans++;
            mx = A;
        }
    }

    cout << ans << "\n";
}