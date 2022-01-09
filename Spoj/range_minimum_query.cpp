#include <bits/stdc++.h>

using namespace std;

#define long long long in

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int log = 32 - __builtin_clz(N);
    vector<vector<int>> rmq(log, vector<int>(N));

    for (int i = 0; i < N; i++)
        rmq[0][i] = a[i];

    for (int i = 1; i < log; i++)
        for (int j = 0; j < N - (1 << i) + 1; j++)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);

    int Q; cin >> Q;
    while (Q--) {
        int i, j;
        cin >> i >> j;

        int idx = 31 - __builtin_clz(j - i + 1);

        int ans = min(rmq[idx][i], rmq[idx][j - (1 << idx) + 1]);
        cout << ans << "\n";
    }
}