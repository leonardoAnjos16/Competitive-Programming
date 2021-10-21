#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;

        int n = s.size();
        int m = t.size();

        bool possible = false;
        for (int i = 0; i < n && !possible; i++)
            for (int j = 0; j < m && !possible; j++)
                if (s[i] == t[j]) possible = true;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}