#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("two2.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        if (N & 1) cout << "-1\n";
        else {
            int ans = N / 2;
            cout << ans << "\n";
        }
    }
}