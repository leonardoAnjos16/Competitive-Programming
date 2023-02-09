#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int twos = 0;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2)
                twos++;
        }

        int idx = 0, curr = 0;
        while (idx < n && curr < twos / 2)
            if (a[idx++] == 2) curr++;

        if (twos & 1) cout << "-1\n";
        else if (!twos) cout << "1\n";
        else cout << idx << "\n";
    }
}