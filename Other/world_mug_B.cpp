#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s.rbegin(), s.rend());

    llong ans = 0LL;
    while (n > 1) {
        for (int i = 0; i < (n >> 1); i++)
            ans += s[i] - s[n - i - 1];

        n >>= 1;
    }

    cout << ans << "\n";
}