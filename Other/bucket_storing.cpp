#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N >> K >> L;

    int ans = (N * K + L - 1) / L;
    cout << ans << "\n";
}