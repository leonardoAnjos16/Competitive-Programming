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

        int cnt[26] = {0};
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;

        bool alphabetical = true;
        for (int i = 0; i < n && alphabetical; i++)
            if (cnt[i] != 1) alphabetical = false;

        if (!alphabetical) {
            cout << "NO\n";
            continue;
        }

        int first_a = 0;
        while (first_a < n && s[first_a] != 'a')
            first_a++;

        if (first_a >= n) cout << "NO\n";
        else {
            for (int i = first_a + 1; i < n && alphabetical; i++)
                if (s[i] <= s[i - 1]) alphabetical = false;

            for (int i = first_a - 1; i >= 0 && alphabetical; i--)
                if (s[i] <= s[i + 1]) alphabetical = false;

            cout << (alphabetical ? "YES" : "NO") << "\n";
        }
    }
}