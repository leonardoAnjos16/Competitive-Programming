#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e9 + 5;

int two_power(int n) {
    return n >= 30 ? MAX : 1 << n;
}

int mult(int a, int b) {
    return 1LL * a * b > MAX ? MAX : a * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> cnt(N + 1, 0);
        for (int i = 0; i < N; i++) {
            int A; cin >> A;
            if (A <= N) cnt[A]++;
        }

        int prod = 1, sum = 0;
        vector<int> mex(N + 1);

        for (int i = 0; i <= N; i++) {
            sum += cnt[i];

            mex[i] = mult(prod, two_power(N - sum));
            if (!i) mex[i]--;

            prod = mult(prod, two_power(cnt[i]) - 1);
        }

        llong ans = 0LL;
        int add = (K + 1) / 2;

        for (int i = 0; i <= N && add; i++) {
            int took = min(mex[i], add);
            ans += 1LL * took * i;
            add -= took;
        }

        int sub = K / 2;
        for (int i = N; i >= 0 && sub; i--) {
            int took = min(mex[i], sub);
            ans -= 1LL * took * i;
            sub -= took;
        }

        cout << ans << "\n";
    }
}