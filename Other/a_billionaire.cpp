#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long MAX = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, E;
    cin >> N >> K >> E;

    long sum = 0LL;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        sum += c;
    }

    long ans = max(1LL * N, (sum - K + E - 1) / E);
    cout << ans << "\n";
}