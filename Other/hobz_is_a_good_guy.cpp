#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hobz.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        bool zero = false;
        for (char c: s)
            if (c == '0')
                zero = true;

        if (zero) cout << "YES\n";
        else if (n > 1) cout << "YES\n";
        else cout << "NO\n";
    }
}