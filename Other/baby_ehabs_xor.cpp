#include <bits/stdc++.h>

using namespace std;

#define long long long int

int LSO(int n) {
    return n & -n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("orxor.in", "r", stdin);

    int n, q;
    cin >> n >> q;

    long sum = 0LL;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    set<int> even, odd;
    for (int i = 1; i <= n; i++) {
        if (!(a[i] & 1)) even.insert(i);
        else if (a[i] != 1) odd.insert(i);
    }

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;

        /* for (auto i: odd) cout << "odd: " << i << "\n";
        for (auto i: even) cout << "even: " << i << "\n"; */

        if (op == 1) {
            vector<int> used;
            for (auto it = even.lower_bound(l); it != even.upper_bound(r); it++) {
                int aux = LSO(a[*it]) - 1;
                sum += aux; a[*it] += aux;

                used.push_back(*it);
                if (a[*it] != 1)
                    odd.insert(*it);
            }

            for (auto i: used) even.erase(i);
        } else {
            vector<int> used;
            for (auto it = odd.lower_bound(l); it != odd.upper_bound(r); it++) {
                sum -= a[*it] - 1; a[*it] = 1;
                used.push_back(*it);
            }

            for (auto i: used) odd.erase(i);

            used.clear();
            for (auto it = even.lower_bound(l); it != even.upper_bound(r); it++) {
                int aux = (LSO(a[*it]) << 1) - 1;
                sum -= a[*it]; sum += aux; a[*it] = aux;

                used.push_back(*it);
                if (a[*it] != 1)
                    odd.insert(*it);
            }

            for (auto i: used) even.erase(i);
        }

        cout << sum << "\n";
    }
}