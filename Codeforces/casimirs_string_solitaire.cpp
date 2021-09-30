#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        int cnt[3] = {0};
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'A']++;

        if (cnt[1] == cnt[0] + cnt[2]) cout << "YES\n";
        else cout << "NO\n";
    }
}