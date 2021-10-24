#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int idx = 0;
    vector<int> ans(n, 0);
    set<int> bag;

    for (int i = 0; i < n; i++) {
        if (bag.count(b[i])) continue;
        while (idx < n && a[idx] != b[i]) {
            ans[i]++;
            bag.insert(a[idx++]);
        }

        ans[i]++;
        bag.insert(a[idx++]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}