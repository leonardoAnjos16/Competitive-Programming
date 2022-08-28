#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> r(1 << n);
    for (int i = 0; i < (1 << n); i++)
        cin >> r[i];

    sort(r.rbegin(), r.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        set<int> aux;
        for (int j = 1 << i; j < (1 << (i + 1)); j++)
            aux.insert(r[j]);

        int cnt = 1 << i;
        for (int j = 0; j < (1 << i); j++) {
            auto it = aux.lower_bound(r[j] - k);
            if (it == aux.end()) cnt--;
            else aux.erase(it);
        }

        ans += cnt;
    }

    cout << ans << "\n";
}