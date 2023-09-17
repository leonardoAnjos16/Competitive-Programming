#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        ans += (H >= A);
    }

    cout << ans << "\n";
}