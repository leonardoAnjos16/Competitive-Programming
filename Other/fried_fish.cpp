#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    if (K >= N) cout << "2\n";
    else {
        int ans = (2 * N + K - 1) / K;
        cout << ans << "\n";
    }
}