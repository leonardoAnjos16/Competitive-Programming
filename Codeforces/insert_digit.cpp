#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;

        string s; cin >> s;

        bool inserted = false;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' >= d || inserted) cout << s[i];
            else cout << d, inserted = true, i--;
        }

        if (!inserted) cout << d;
        cout << "\n";
    }
}