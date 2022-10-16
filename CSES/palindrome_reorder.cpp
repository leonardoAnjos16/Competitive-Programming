#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int cnt[MAX] = {0}, odd = 0;
    for (char c: s) {
        if (++cnt[c - 'A'] & 1) odd++;
        else odd--;
    }

    if (odd > 1) cout << "NO SOLUTION\n";
    else {
        char mid = '-';
        string ans = "";

        for (char c = 'A'; c <= 'Z'; c++) {
            if (cnt[c - 'A'] & 1) mid = c;
            else ans += string(cnt[c - 'A'] / 2, c);
        }

        if (mid != '-') ans += string(cnt[mid - 'A'], mid);

        for (char c = 'Z'; c >= 'A'; c--)
            if (!(cnt[c - 'A'] & 1))
                ans += string(cnt[c - 'A'] / 2, c);

        cout << ans << "\n";
    }
}