#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

int cnt[MAX] = {0}, last_prime[MAX] = {0};

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

    last_prime[1] = 1;
    for (int i = 2; i < MAX; i++)
        if (!last_prime[i])
            for (int j = i; j < MAX; j += i)
                last_prime[j] = i;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int V; cin >> V;

        vector<int> primes;
        while (V > 1) {
            int p = last_prime[V];
            primes.push_back(p);

            while (last_prime[V] == p)
                V /= last_prime[V];
        }

        int sz = primes.size();
        for (int j = 0; j < (1 << sz); j++) {
            int div = 1;
            for (int k = 0; k < sz; k++)
                if (j & (1 << k))
                    div *= primes[k];

            cnt[div]++;
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int X; cin >> X;

        vector<int> primes;
        while (X > 1) {
            int p = last_prime[X];
            primes.push_back(p);

            while (last_prime[X] == p)
                X /= last_prime[X];
        }

        int sz = primes.size(), rem = 0;
        for (int i = 0; i < (1 << sz); i++) {
            int div = 1;
            for (int j = 0; j < sz; j++)
                if (i & (1 << j))
                    div *= primes[j];

            if (__builtin_popcount(i) & 1) rem -= cnt[div];
            else rem += cnt[div];
        }

        assert(rem <= N);

        int ans = exp(2, rem);
        cout << ans << "\n";
    }
}