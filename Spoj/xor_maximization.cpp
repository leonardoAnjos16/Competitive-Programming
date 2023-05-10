#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 62;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    llong basis[MAX] = {0LL};
    for (int i = 0; i < N; i++) {
        llong a; cin >> a;

        bool done = false;
        for (int j = MAX - 1; j >= 0 && !done; j--) {
            if (!(a & (1LL << j))) continue;

            if (basis[j]) a ^= basis[j];
            else {
                done = true;
                basis[j] = a;
            }
        }
    }

    llong ans = 0LL;
    for (int i = MAX - 1; i >= 0; i--)
        if (basis[i] && !(ans & (1LL << i)))
            ans ^= basis[i];

    cout << ans << "\n";
}