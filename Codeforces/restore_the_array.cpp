#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> b(n - 1);
        for (int i = 1; i < n; i++)
            cin >> b[i - 1];

        vector<int> a(n, 0);
        a[0] = b[0];

        int idx = 1;
        for (int i = 1; i < n && idx + 1 < n; i++) {
            if (idx == i && b[idx] > b[idx - 1]) a[i] = b[idx - 1];
            else if (idx < i && b[idx] == b[idx - 1] && (idx + 2 >= n || b[idx + 1] <= b[idx])) {
                if (idx + 2 < n) a[i] = b[++idx];
                idx++;
            }
            else a[i] = b[idx++];
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << a[i];
        }

        cout << "\n";
    }
}