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
            for (int j = i; j < n && !possible; j++) {
                int idx = 0;
                possible = true;

                int size = j - i + 1 + j;
                if (j - i + 1 > m || size < m) possible = false;

                for (int k = i; k <= j && possible; k++, idx++)
                    if (s[k] != t[idx]) possible = false;

                for (int k = j - 1; idx < m && possible; k--, idx++)
                    if (s[k] != t[idx]) possible = false;
            }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}