#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int basis[MAX] = {0}, sz = 0;
    while (n--) {
        int t, k;
        cin >> t >> k;

        if (t == 1) {
            bool done = false;
            for (int i = MAX - 1; i >= 0 && !done; i--) {
                if (!(k & (1 << i))) continue;

                if (basis[i]) k ^= basis[i];
                else basis[i] = k, sz++, done = true;
            }
        } else {
            int ans = 0, seen = 0;
            for (int i = MAX - 1; i >= 0; i--) {
                if (!basis[i]) continue;

                int rem = 1 << (sz - ++seen);
                if (k > rem) {
                    k -= rem;
                    if (!(ans & (1 << i)))
                        ans ^= basis[i];
                } else if (ans & (1 << i)) {
                    ans ^= basis[i];
                }
            }

            cout << ans << "\n";
        }
    }
}