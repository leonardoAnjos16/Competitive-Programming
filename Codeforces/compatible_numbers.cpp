#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 24;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    bool present[1 << LOG] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        present[a[i]] = true;
    }

    int ans[1 << LOG];
    memset(ans, -1, sizeof ans);

    for (int i = 0; i < (1 << LOG); i++)
        if (present[i]) ans[i] = i;

    for (int i = 0; i < LOG; i++)
        for (int j = 0; j < (1 << LOG); j++)
            if (j & (1 << i))
                ans[j] = max(ans[j], ans[j ^ (1 << i)]);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[~a[i] & ((1 << LOG) - 1)];
    }

    cout << "\n";
}