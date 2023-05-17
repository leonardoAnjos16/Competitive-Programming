#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

template<const int D, typename T>
struct XorGauss {
private:
    T basis[D];

public:
    XorGauss() {
        memset(basis, 0, sizeof basis);
    }

    bool add(T x) {
        for (int i = D - 1; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;

            if (basis[i]) x ^= basis[i];
            else {
                basis[i] = x;
                return true;
            }
        }

        return false;
    }

    T reduce(T x) {
        for (int i = D - 1; i >= 0; i--)
            x = min(x, x ^ basis[i]);
    }

    T augment(T x) {
        return ~reduce(~x);
    }
};

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int sz = 0;
    XorGauss<60, llong> solver;

    for (int i = 0; i < N; i++) {
        llong A; cin >> A;
        sz += solver.add(A);
    }

    int ans = (exp(2, N) - exp(2, N - sz) + MOD) % MOD;
    cout << ans << "\n";
}