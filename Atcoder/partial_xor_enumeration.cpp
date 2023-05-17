#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 60;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; llong L, R;
    cin >> N >> L >> R;

    int sz = 0;
    llong basis[MAX] = {0LL};

    for (int i = 0; i < N; i++) {
        llong A; cin >> A;

        bool done = false;
        for (int j = MAX - 1; j >= 0 && !done; j--) {
            if (!(A & (1LL << j))) continue;

            if (basis[j]) A ^= basis[j];
            else basis[j] = A, sz++, done = true;
        }
    }

    for (llong i = L; i <= R; i++) {
        if (i > L) cout << " ";

        int seen = 0;
        llong ans = 0LL;
        llong k = (1LL << sz) - i + 1LL;

        for (int j = MAX - 1; j >= 0; j--) {
            if (!basis[j]) continue;

            llong cnt = 1LL << (sz - ++seen);
            if (cnt >= k) ans = max(ans, ans ^ basis[j]);
            else ans = min(ans, ans ^ basis[j]), k -= cnt;
        }

        cout << ans;
    }

    cout << "\n";
}