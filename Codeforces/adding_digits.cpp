#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, n;
    cin >> a >> b >> n;

    bool possible = false;
    for (int i = 0; i <= 9 && !possible; i++)
        if (!((a * 10 + i) % b)) {
            possible = true;
            a = a * 10 + i; n--;
        }

    if (!possible) cout << "-1\n";
    else {
        string ans = to_string(a);
        for (int i = 0; i < n; i++)
            ans += "0";

        cout << ans << "\n";
    }
}