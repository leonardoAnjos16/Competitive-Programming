#include <bits/stdc++.h>

using namespace std; 

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<tuple<int, int, int>> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto it = sums.lower_bound(make_tuple(x - a[i] - a[j], 0, 0));
            if (it != sums.end() && get<0>(*it) == x - a[i] - a[j]) {
                cout << (i + 1) << " " << (j + 1) << " " << get<1>(*it) << " " << get<2>(*it) << "\n";
                return 0;
            }
        }

        for (int j = 0; j < i; j++)
            sums.emplace(a[i] + a[j], i + 1, j + 1);
    }

    cout << "IMPOSSIBLE\n";
}