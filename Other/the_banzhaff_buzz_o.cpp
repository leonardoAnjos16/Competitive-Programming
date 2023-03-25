#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 61;

llong comb[MAX][MAX];

int n, q;
vector<int> w, m;
vector<vector<llong>> memo;

llong count(int chosen, int i = 0, int sum = 0) {
    if (i >= n) return sum >= q && sum - w[chosen] < q;

    llong &ans = memo[i][sum];
    if (~ans) return ans;

    ans = 0LL;
    for (int j = (i == chosen ? 1 : 0); j <= m[i]; j++) {
        llong aux = i == chosen ? comb[m[i] - 1][j - 1] : comb[m[i]][j];
        ans += aux * count(chosen, i + 1, sum + j * w[i]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }

    int t = 1;
    while (cin >> n >> q, n || q) {
        w.resize(n);
        m.resize(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> m[i];
            sum += w[i] * m[i];
        }

        cout << "Case " << t++ << ":";
        for (int i = 0; i < n; i++) {
            memo.assign(n + 5, vector<llong>(sum + 5, -1LL));

            llong ans = count(i);
            cout << " " << ans;
        }

        cout << "\n";
    }
}