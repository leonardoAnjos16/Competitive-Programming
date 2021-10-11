#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);

    int k; cin >> k;

    string ans(k, 'a');
    cout << ans << "\n";

    for (int i = 1; i < k; i++) {
        ans[i - 1] = 'b';
        ans[i] = 'B';

        cout << ans << "\n";
        ans[i - 1] = ans[i] = 'a';
    }
}