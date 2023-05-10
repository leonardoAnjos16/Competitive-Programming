#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> c(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> c[i][j];

    while (Q--) {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int j = lower_bound(c[i].begin(), c[i].end(), a) - c[i].begin();

            int l = 0, r = N - max(i, j) - 1, k = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (c[i + mid][j + mid] > b) r = mid - 1;
                else l = mid + 1, k = mid;
            }

            ans = max(ans, (k + 1) * (k + 1));
        }

        cout << ans << "\n";
    }
}