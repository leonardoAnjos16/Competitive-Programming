#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> long_pair;

const ll MOD = 1e9 + 7;

int main() {
    ll N, K; scanf("%lld %lld", &N, &K);
    ll mult = 1;

    stack<long_pair> chefs;
    for (ll i = 0; i < N; i++) {
        ll chef; scanf("%lld", &chef);

        while (!chefs.empty() && chefs.top().second > chef)
            mult = (mult * (i - chefs.top().first + 1)) % MOD, chefs.pop();

        chefs.push({i, chef});
    }

    printf("%lld\n", mult);
}