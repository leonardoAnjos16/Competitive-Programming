#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int N, A, B;
    cin >> N >> A >> B;

    bool zero = false;
    if (!A) {
        A++;
        zero = true;
    }

    vector<ldouble> dp(N + 1, 0.0L), ps(N + 1, 0.0L);
    for (int i = 1; i <= N; i++) {
        ldouble sum = (i - A >= 0 ? ps[i - A] : ps[0]);
        sum -= (i - B > 0 ? ps[i - B - 1] : ps[0]);

        dp[i] = 1.0L / (B - A + 1.0L) * sum + 1.0L;
        if (zero) dp[i] += 1.0L / B;
        ps[i] = ps[i - 1] + dp[i];
    }

    ldouble ans = dp[N];
    cout << ans << "\n";
}