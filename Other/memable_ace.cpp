#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("max-pair.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int n = S.size();

        int ans = n - (S[0] == S[n - 1] ? 2 : 1);
        cout << ans << "\n";
    }
}