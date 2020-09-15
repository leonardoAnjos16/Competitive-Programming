#include <bits/stdc++.h>

using namespace std;

bool all_equal(string s, int n) {
    for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1]) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string t; cin >> t;
        int n = t.size();

        if (all_equal(t, n)) cout << t << "\n";
        else {
            string s = "";
            for (int i = 0; i < n; i++)
                s += "01";

            cout << s << "\n";
        }
    }
}