#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];

        vector<int> t(k);
        for (int i = 0; i < k; i++)
            cin >> t[i];

        vector<int> aux(n, 0);
        for (int i = 0; i < k; i++)
            aux[a[i] - 1] = t[i];

        int mn = INF;
        vector<int> ans(n, INF);

        for (int i = 0; i < n; i++) {
            if (aux[i])
                mn = min(mn, aux[i] - i);

            ans[i] = mn + i;
        }

        mn = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (aux[i])
                mn = min(mn, aux[i] + i);

            ans[i] = min(ans[i], mn - i);
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}

// min(tj + |aj - i|) forall j in [1, k]
/* min(
    min(tj - aj + i) forall j in [1, k], aj <= i,
    min(tj + aj - i) forall j in [1, k], aj > i
) */