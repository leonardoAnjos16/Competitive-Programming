#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

int last_prime[MAX] = {0};
vector<int> primes[MAX];

void get_primes(int x) {
    vector<int> &ans = primes[x];
    if (!ans.empty()) return;

    while (x > 1) {
        int prime = last_prime[x];
        while (x > 1 && last_prime[x] == prime)
            x /= prime;

        ans.push_back(prime);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < MAX; i++)
        if (!last_prime[i])
            for (int j = i; j < MAX; j += i)
                last_prime[j] = i;

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> c(Q), d(Q);
    for (int i = 0; i < Q; i++)
        cin >> c[i] >> d[i];

    int max_size = N;
    llong sums[MAX] = {0LL};
    vector<int> l(N, 0), r(N, Q - 1), ans(N, -1);

    while (max_size > 1) {
        max_size = 0;
        vector<vector<int>> groups(Q, vector<int>());

        for (int i = 0; i < N; i++)
            if (l[i] <= r[i]) {
                int mid = (l[i] + r[i]) / 2;
                groups[mid].push_back(i + 1);

                int sz = groups[mid].size();
                max_size = max(max_size, sz);
            }

        memset(sums, 0, sizeof sums);
        for (int i = 0; i < Q; i++) {
            get_primes(c[i]);
            int num_primes = primes[c[i]].size();

            for (int j = 1; j < (1 << num_primes); j++) {
                int num = 1;
                for (int k = 0; k < num_primes; k++)
                    if (j & (1 << k))
                        num *= primes[c[i]][k];

                sums[num] += (__builtin_popcount(j) & 1 ? d[i] : -d[i]);
            }

            for (int id: groups[i]) {
                get_primes(id);
                num_primes = primes[id].size();

                llong sum = 0LL;
                for (int j = 1; j < (1 << num_primes); j++) {
                    int num = 1;
                    for (int k = 0; k < num_primes; k++)
                        if (j & (1 << k))
                            num *= primes[id][k];

                    sum += sums[num];
                }

                if (sum < A[id - 1]) l[id - 1] = i + 1;
                else r[id - 1] = i - 1, ans[id - 1] = i + 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << "\n";
}