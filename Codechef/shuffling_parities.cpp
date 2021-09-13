#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int even = 0, odd = 0;
        for (int i = 0; i < N; i++) {
            int A; cin >> A;
            if (A & 1) odd++;
            else even++;
        }

        int ans = min(N / 2, odd) + min((N + 1) / 2, even);
        cout << ans << "\n";
    }
}