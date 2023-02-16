#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int cnt[MAX] = {0};
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;

            if (l <= k && k <= r)
                for (int j = l; j <= r; j++)
                    cnt[j]++;
        }

        bool possible = true;
        for (int i = 0; i < MAX && possible; i++)
            if (i != k && cnt[i] >= cnt[k])
                possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}