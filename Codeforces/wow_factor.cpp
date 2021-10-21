#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    vector<int> ps(n + 1, 0);
    for (int i = 2; i <= n; i++)
        ps[i] = ps[i - 1] + (s[i - 2] == 'v' && s[i - 1] == 'v');

    long ans = 0LL;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o')
            ans += 1LL * ps[i] * (ps[n] - ps[i + 1]);

    cout << ans << "\n";
}