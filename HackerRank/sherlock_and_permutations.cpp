#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;

ll pow_mod(ll a, ll exp) {
    if (exp == 0) return 1;
    else if (exp % 2) return (a * pow_mod(a, exp - 1)) % MOD;
    else {
        ll aux = pow_mod(a, exp / 2);
        return (aux * aux) % MOD;
    }
}

ll fact_mod(ll n, ll exp = 1) {
    if (n == 0) return 1;
    else return (n * fact_mod(n - 1)) % MOD;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        ll N, M; scanf("%lld %lld", &N, &M);

        ll num = fact_mod(N + M - 1);
        ll n_fact = fact_mod(N);
        ll m_fact = fact_mod(M - 1);
        ll denom = (n_fact * m_fact) % MOD;
        denom = pow_mod(denom, MOD - 2);

        ll answer = (num * denom) % MOD;
        printf("%lld\n", answer);
    }
}