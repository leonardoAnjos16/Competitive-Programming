#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string s; cin >> s;

    string best = to_string(s[0]);
    for (int i = 1; i < N; i++) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < N && s[l] == s[r]) l--, r++;
        l++; r--;

        if (r - l + 1 > (int) best.size())
            best = s.substr(l, r - l + 1);

        if (s[i] == s[i - 1]) {
            int l = i - 2, r = i + 1;
            while (l >= 0 && r < N && s[l] == s[r]) l--, r++;
            l++; r--;

            if (r - l + 1 > (int) best.size())
                best = s.substr(l, r - l + 1);
        }
    }

    int ans = best.size();
    cout << ans << "\n";
    cout << best << "\n";
}