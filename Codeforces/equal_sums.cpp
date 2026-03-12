#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k; cin >> k;

    map<int, pair<int, int>> sums;
    pair<int, int> fst = make_pair(-1, -1), snd(-1, -1);

    for (int i = 1; i <= k; i++) {
        int n; cin >> n;

        int sum = 0;
        vector<int> a(n);

        for (int j = 0; j < n; j++) {
            cin >> a[j];
            sum += a[j];
        }

        for (int j = 0; j < n; j++)
            if (sums.count(sum - a[j])) {
                fst = sums[sum - a[j]];
                snd = make_pair(i, j + 1);
            }

        for (int j = 0; j < n; j++)
            sums[sum - a[j]] = make_pair(i, j + 1);
    }

    if (fst.first == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << fst.first << " " << fst.second << "\n";
        cout << snd.first << " " << snd.second << "\n";
    }
}