#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    int cnt_s[MAX] = {0};
    int cnt_t[MAX] = {0};

    for (int i = 1; i < n; i++)
        cnt_s[s[i] - 'a']++;

    for (int i = 0; i < m - 1; i++)
        cnt_t[t[i] - 'a']++;

    long ans = 1LL * n * m;
    for (int i = 0; i < MAX; i++)
        ans -= 1LL * cnt_s[i] * cnt_t[i];

    cout << ans << "\n";
}