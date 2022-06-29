#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        vector<int> l(N + 1, 0);
        for (int i = 1; i <= N; i++)
            l[i] = gcd(l[i - 1], A[i]);

        vector<int> r(N + 2, 0);
        for (int i = N; i > 0; i--)
            r[i] = gcd(r[i + 1], A[i]);

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int g = gcd(l[i - 1], r[i + 1]);
            if (g != l[N] || g > 1) ans++;
        }

        cout << ans << "\n";
    }
}