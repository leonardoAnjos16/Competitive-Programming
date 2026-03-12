#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans(m, 0), last(m, -1);
    while (k--) {
        int p, c;
        cin >> p >> c;

        if (last[c - 1] == -1) last[c - 1] = p;
        else if (last[c - 1] == p) ans[c - 1] += 100, last[c - 1] = -1;
        else ans[c - 1] += abs(last[c - 1] - p), last[c - 1] = -1;
    }

    for (int i = 0; i < m; i++) {
        if (last[i] != -1)
            ans[i] += 100;

        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}