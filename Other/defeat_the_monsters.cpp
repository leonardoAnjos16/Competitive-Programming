#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        map<int, int> cnt;
        while (N--) {
            int A; cin >> A;
            for (int i = 2; i * i <= A; i++) {
                if (A % i == 0) cnt[i]++;
                while (A % i == 0) A /= i;
            }

            if (A > 1) cnt[A]++;
        }

        long ans = 0LL;
        for (auto [p, c]: cnt)
            ans += (c + 2) / 3;

        cout << ans << "\n";
    }
}