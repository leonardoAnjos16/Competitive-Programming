#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    // N * x + N - 1 <= K
    // N * (x + 1) <= K + 1
    // x + 1 <= (K + 1) / N
    // x <= (K + 1) / N - 1

    int ans = (K + 1) / N - 1;
    cout << ans << "\n";
}