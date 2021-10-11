#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);

    string s; cin >> s;
    int n = s.size();

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != '-') ans += s[i];
        else {
            ans += "-";
            ans += s[++i];

            string num = "";
            while (i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '9')
                num += s[++i];

            if (num.empty()) continue;

            int idx = 0, sz = num.size();
            while (idx < sz && num[idx] == '0') {
                idx++;
                ans += "+0";
            }

            if (idx < sz) {
                num = num.substr(idx);
                if (!num.empty()) ans += "+" + num;
            }
        }
    }

    cout << ans << "\n";
}