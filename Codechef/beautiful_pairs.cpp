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
        for (int i = 0; i < N; i++) {
            int A;
            cin >> A;
            cnt[A]++;
        }

        long ans = N * (N - 1LL);
        for (auto p: cnt)
            ans -= p.second * (p.second - 1LL);

        cout << ans << "\n";
    }
}