#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int n = S.size();

    int cnt[2] = {0};
    for (char c: S)
        cnt[c - '0']++;

    string ans(n, cnt[0] < cnt[1] || (cnt[0] == cnt[1] && S[0] == '0') ? '0' : '1');
    if (cnt[0] == cnt[1]) ans[0] = (char) ('0' + 1 - (S[0] - '0'));
    cout << ans << "\n";
}