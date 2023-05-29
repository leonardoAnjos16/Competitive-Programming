#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    map<string, int> cnt;
    while (N--) {
        int X; cin >> X;

        string name = "";
        while (X--) {
            string s; cin >> s;
            name += s[0];
        }

        cnt[name]++;
    }

    int ans = 0;
    for (auto [name, c]: cnt)
        if (c == 1) ans++;

    cout << ans << "\n";
}