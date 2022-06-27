#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int BLOCK_SIZE = 250;
const int MAX = 5e5 + 5;

struct Query {
    int l, r, idx;

    Query() {}
    Query(int l, int r, int idx): l(l), r(r), idx(idx) {}

    bool operator <(const Query &other) const {
        if ((l / BLOCK_SIZE) != (other.l / BLOCK_SIZE))
            return l < other.l;

        if ((l / BLOCK_SIZE) & 1)
            return r > other.r;

        return r < other.r;
    }
};

int add(int cnt[MAX], array<vector<int>, 2> &divisors) {
    int sum = 0;
    for (int divisor: divisors[1])
        sum += cnt[divisor]++;

    for (int divisor: divisors[0])
        sum -= cnt[divisor]++;

    return sum;
}

int remove(int cnt[MAX], array<vector<int>, 2> &divisors) {
    int sum = 0;
    for (int divisor: divisors[1])
        sum += --cnt[divisor];

    for (int divisor: divisors[0])
        sum -= --cnt[divisor];

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<array<vector<int>, 2>> divisors(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;

        vector<int> primes;
        for (int j = 2; j * j <= a; j++) {
            if (!(a % j)) primes.push_back(j);
            while (!(a % j)) a /= j;
        }

        if (a > 1) primes.push_back(a);

        int size = primes.size();
        for (int j = 1; j < (1 << size); j++) {
            int prod = 1;
            for (int k = 0; k < size; k++)
                if (j & (1 << k)) prod *= primes[k];

            divisors[i][__builtin_popcount(j) & 1].push_back(prod);
        }
    }

    vector<Query> queries(M);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = Query(l - 1, r - 1, i);
    }

    sort(queries.begin(), queries.end());

    int cnt[MAX] = {0};
    vector<bool> ans(M);

    long pairs = 0LL;
    int l = 0, r = -1;

    for (Query query: queries) {
        while (l > query.l)
            pairs += add(cnt, divisors[--l]);

        while (r < query.r)
            pairs += add(cnt, divisors[++r]);

        while (l < query.l)
            pairs -= remove(cnt, divisors[l++]);

        while (r > query.r)
            pairs -= remove(cnt, divisors[r--]);

        int size = r - l + 1;
        ans[query.idx] = pairs < size * (size - 1LL) / 2LL;
    }

    for (int i = 0; i < M; i++)
        cout << (ans[i] ? "S" : "N") << "\n";
}