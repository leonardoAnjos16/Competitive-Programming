#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0, keys[26] = {0};
    for (int i = 0; i < 2 * n - 2; i += 2) {
        keys[s[i] - 'a']++;
        if (!keys[s[i + 1] - 'A']) ans++;
        else keys[s[i + 1] - 'A']--;
    }

    cout << ans << "\n";
}