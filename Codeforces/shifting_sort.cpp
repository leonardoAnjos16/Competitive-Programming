#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n), sorted(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted[i] = a[i];
        }

        sort(sorted.begin(), sorted.end());

        vector<tuple<int, int, int>> ans;
        for (int i = 0; i < n; i++) {
            int idx = i;
            while (idx < n && a[idx] != sorted[i]) idx++;

            assert(idx < n);
            if (idx > i) {
                int aux = a[idx];
                for (int j = idx; j > i; j--)
                    a[j] = a[j - 1];

                a[i] = aux;
                ans.push_back(make_tuple(i + 1, idx + 1, idx - i));
            }
        }

        int cnt = ans.size();
        cout << cnt << "\n";

        for (auto [l, r, d]: ans)
            cout << l << " " << r << " " << d << "\n";
    }
}