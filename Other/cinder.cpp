#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<string, int> cnt;
    while (n--) {
        string s; cin >> s;
        if (!cnt[s]++) cout << "OK\n";
        else {
            string ans = s + to_string(cnt[s] - 1);
            cout << ans << "\n";
        }
    }
}