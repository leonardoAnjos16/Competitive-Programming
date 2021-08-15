#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<long> factors(N);
        for (int i = 0; i < N; i++) {
            int A; cin >> A;

            map<int, int> cnt;
            for (int j = 2; j * j <= A; j++)
                while (!(A % j)) cnt[j]++, A /= j;

            if (A > 1) cnt[A]++;

            long odds = 1LL;
            for (auto p: cnt)
                if (p.second % 2)
                    odds *= p.first;

            factors[i] = odds;
        }

        long ans = 0LL;
        map<long, int> cnt;

        for (int i = 0; i < N; i++) {
            ans += i - cnt[factors[i]];
            cnt[factors[i]]++;
        }

        cout << ans << "\n";
    }
}