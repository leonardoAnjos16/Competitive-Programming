#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int M;
vector<int> balance, sum;
vector<int> memo;

int max_groups(int need) {
    if (!need) return 0;

    int &ans = memo[need];
    if (~ans) return ans;

    ans = !sum[need] ? 1 : -INF;
    for (int i = 0; i < M; i++)
        if (need & (1 << i))
            ans = max(ans, max_groups(need ^ (1 << i)) + !sum[need]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> M >> N;

    balance.assign(M, 0);
    for (int i = 0; i < N; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        balance[a] -= p;
        balance[b] += p;
    }

    sum.assign(1 << M, 0);
    for (int i = 0; i < (1 << M); i++)
        for (int j = 0; j < M; j++)
            if (i & (1 << j))
                sum[i] += balance[j];

    memo.assign((1 << M) + 5, -1);

    int ans = M - max_groups((1 << M) - 1);
    cout << ans << "\n";
}