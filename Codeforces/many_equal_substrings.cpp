#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string t; cin >> t;

    string ans = "";
    bool found = false;

    for (int i = 1; i <= n && !found; i++) {
        string aux = t, suffix = t.substr(n - i);
        for (int j = 1; j < k; j++) aux += suffix;

        int cnt = 0;
        for (int j = n - 1; j < (int) aux.size(); j++)
            if (aux.substr(j - n + 1, n) == t) cnt++;

        if (cnt == k) {
            ans = aux;
            found = true;
        }
    }

    cout << ans << "\n";
}