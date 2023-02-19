#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string p; cin >> p;

        bool substr = true;
        for (int i = 1; i < (int) p.size() && substr; i++)
            if (p[i] != (char) 'a' + ((p[i - 1] - 'a' + 1) % ('z' - 'a' + 1)))
                substr = false;

        cout << (substr ? "YES" : "NO") << "\n";
    }
}