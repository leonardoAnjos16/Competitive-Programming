#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    int ans = 0;
    for (int i = m - 1; i < n; i++) {
        bool possible = true;
        int start = i - m + 1;

        for (int j = start; j <= i && possible; j++)
            if (s[j] == t[j - start]) possible = false;

        if (possible) ans++;
    }

    cout << ans << "\n";
}