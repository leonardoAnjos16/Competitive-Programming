#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> even, peven, odd, podd;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a & 1) {
                odd.push_back(a);
                podd.push_back(i);
            } else {
                even.push_back(a);
                peven.push_back(i);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        vector<int> sorted(n);
        for (int i = 0; i < (int) even.size(); i++)
            sorted[peven[i]] = even[i];

        for (int i = 0; i < (int) odd.size(); i++)
            sorted[podd[i]] = odd[i];

        bool possible = true;
        for (int i = 1; i < n && possible; i++)
            if (sorted[i] < sorted[i - 1])
                possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}