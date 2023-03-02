#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string FB = "";
    for (int i = 1; i < MAX; i++) {
        if (!(i % 3)) FB += 'F';
        if (!(i % 5)) FB += 'B';
    }

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        string s; cin >> s;

        bool ans = false;
        for (int i = k - 1; i < (int) FB.size() && !ans; i++)
            if (FB.substr(i - k + 1, k) == s) ans = true;

        cout << (ans ? "YES" : "NO") << "\n";
    }
}