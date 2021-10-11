#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);

    int b, w;
    cin >> b >> w;

    int idx = 1;
    vector<string> ans(2, string(50000, '@'));

    while (--b) {
        ans[0][idx] = ans[1][idx - 1] = ans[1][idx] = '.';
        idx += 2;
    }

    if (ans[0][1] == '.') w--;
    while (w--) {
        ans[0][idx] = '.';
        idx += 2;
    }

    cout << "2 50000\n";
    cout << ans[0] << "\n" << ans[1] << "\n";
}