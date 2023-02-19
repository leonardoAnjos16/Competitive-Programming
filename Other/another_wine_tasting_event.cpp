#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'W') cnt++;

    int ans = cnt;
    for (int i = n; i < 2 * n - 1; i++) {
        if (s[i - n] == 'W') cnt--;
        if (s[i] == 'W') cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}