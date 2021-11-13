#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, b;
    cin >> n >> c >> b;

    string ans(n, '-');
    for (int i = 0; i < b; i++) {
        int z; cin >> z;
        ans[--z] = '0';
    }

    ans[0] = c & 1 ? '1' : '0';
    int idx = 1, changes = 0;

    while (idx < n) {
        if (changes >= c && ans[idx] != '0')
            ans[idx] = ans[idx - 1];
        else if (ans[idx] != '0')
            ans[idx] = (ans[idx - 1] == '0' ? '1' : '0');

        changes += ans[idx] != ans[idx - 1];
        idx++;
    }

    assert(changes == c);
    cout << ans << "\n";
}