#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        string s, t;
        cin >> s >> t;

        int diff[MAX] = {0};
        for (char c: s) diff[c - 'a']++;
        for (char c: t) diff[c - 'a']--;

        bool same_letters = true;
        for (int i = 0; i < MAX && same_letters; i++)
            if (diff[i]) same_letters = false;

        if (!same_letters) cout << "NO\n";
        else if (n >= 2 * k) cout << "YES\n";
        else {
            int l = max(min(n - k, n - 1), 0);
            int r = max(min(k - 1, n - 1), 0);
            int size = r - l + 1;

            if (s.substr(l, size) == t.substr(l, size)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}