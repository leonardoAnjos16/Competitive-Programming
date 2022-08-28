#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> equal(n + 1, 0);
    for (int i = 1; i <= n; i++)
        equal[i] = s[i - 1] != t[i - 1] ? 0 : equal[i - 1] + 1;

    llong ans = 0LL;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] < t[i - 1]) {
            int idx = i - equal[i - 1] - 1;
            ans += (i - idx) * (n - i + 1LL);
        }

    cout << ans << "\n";
}