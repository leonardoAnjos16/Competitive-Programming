#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bad-memes.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<long> ps(N + 1, 0LL);
        for (int i = 1; i <= N; i++) {
            int A; cin >> A;
            ps[i] = ps[i - 1] + A;
        }

        long ans = LLONG_MIN;
        for (int i = 1; i <= N; i++) {
            long mn = LLONG_MAX;
            for (int j = i; j <= N; j += i)
                mn = min(mn, ps[j] - ps[j - i]);

            if (N % i)
                mn = min(mn, ps[N] - ps[N - N % i]);

            ans = max(ans, mn);
        }

        cout << ans << "\n";
    }
}