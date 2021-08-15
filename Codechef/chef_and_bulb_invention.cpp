#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, p, K;
        cin >> N >> p >> K;

        int ans = (p % K) * (N / K);
        ans += min(N % K, p % K);
        ans += p / K + 1;

        cout << ans << "\n";
    }
}