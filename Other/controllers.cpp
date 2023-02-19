#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int plus = 0, minus = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') plus++;
        else minus++;
    }

    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a == b) cout << (plus == minus ? "YES" : "NO") << "\n";
        else {
            llong k = 1LL * (minus - plus) * b / (a - b);
            if (k * (a - b) != 1LL * (minus - plus) * b) cout << "NO\n";
            else if (k < -minus || k > plus) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}