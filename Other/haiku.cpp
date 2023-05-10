#include <bits/stdc++.h>

using namespace std;

#define llong long long int

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    vector<int> ps(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;

        int cnt = 0, idx = 0;
        while (idx < (int) s.size()) {
            while (idx < (int) s.size() && !vowel(s[idx])) idx++;

            if (idx < (int) s.size()) {
                cnt++;
                while (idx < (int) s.size() && vowel(s[idx])) idx++;
            }
        }

        ps[i] = ps[i - 1] + cnt;

        auto i1 = lower_bound(ps.begin(), ps.begin() + i, ps[i] - 5);
        if (i1 != ps.begin() + i && *i1 == ps[i] - 5) {
            auto i2 = lower_bound(ps.begin(), i1, *i1 - 7);
            if (i2 != i1 && *i2 == *i1 - 7) {
                auto i3 = lower_bound(ps.begin(), i2, *i2 - 5);
                if (i3 != i2 && *i3 == *i2 - 5) ans++;
            }
        }
    }

    cout << ans << "\n";
}