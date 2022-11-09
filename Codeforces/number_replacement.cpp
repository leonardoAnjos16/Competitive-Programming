#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        string s; cin >> s;

        map<int, char> id;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            if (id.count(a[i]) && id[a[i]] != s[i]) possible = false;
            id[a[i]] = s[i];
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}