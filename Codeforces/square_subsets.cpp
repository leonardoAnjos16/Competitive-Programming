#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 71;
const int MOD = 1e9 + 7;

int mask[MAX], cnt[2][MAX] = {0}, memo[MAX][1 << 19];

int count(int num = 1, int curr_mask = 0) {
    if (num >= MAX) return !curr_mask;

    int &ans = memo[num][curr_mask];
    if (~ans) return ans;

    ans = (1LL * count(num + 1, curr_mask) * cnt[0][num]) % MOD;
    ans = (ans + 1LL * count(num + 1, curr_mask ^ mask[num]) * cnt[1][num]) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> composite;
    for (int i = 2; i * i < MAX; i++)
        if (!composite[i])
            for (int j = i * i; j < MAX; j += i)
                composite[j] = true;

    vector<int> primes;
    for (int i = 2; i < MAX; i++)
        if (!composite[i])
            primes.push_back(i);

    int id[MAX], idx = 0;
    for (int p: primes)
        id[p] = idx++;

    for (int i = 1; i < MAX; i++) {
        int aux = i;
        mask[i] = 0;
        cnt[0][i] = 1;

        for (int j = 2; j * j <= aux; j++)
            while (!(aux % j)) {
                aux /= j;
                mask[i] ^= (1 << id[j]);
            }

        if (aux > 1) mask[i] ^= (1 << id[aux]);
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        int aux = cnt[0][a];
        cnt[0][a] = (cnt[0][a] + cnt[1][a]) % MOD;
        cnt[1][a] = (cnt[1][a] + aux) % MOD;
    }

    memset(memo, -1, sizeof memo);

    int ans = (count() - 1 + MOD) % MOD;
    cout << ans << "\n";
}