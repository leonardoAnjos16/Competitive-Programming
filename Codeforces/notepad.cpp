#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        set<string> seen;
        bool possible = false;

        for (int i = 2; i + 1 < n && !possible; i++) {
            seen.insert(s.substr(i - 2, 2));
            if (seen.find(s.substr(i, 2)) != seen.end())
                possible = true;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}