#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("help.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<long> sum(N + 1, 0LL);
        int mx = INT_MIN, snd_mx = INT_MIN;

        for (int i = 1; i <= N; i++) {
            int A; cin >> A;
            sum[i] = sum[i - 1] + A;

            if (A > mx) {
                int aux = mx;
                mx = A;
                snd_mx = aux;
            } else if (A > snd_mx) {
                snd_mx = A;
            }
        }

        long ans = sum[N] - mx - snd_mx;
        for (int i = 2; i <= N; i++)
            ans = min(ans, max(sum[i - 2], sum[N] - sum[i]));

        cout << ans << "\n";
    }
}