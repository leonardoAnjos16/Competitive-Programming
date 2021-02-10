#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string year = "2020";
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        bool possible = false;
        for (int i = 0; i <= 4 && !possible; i++) {
            string init = s.substr(0, i);
            string end = s.substr(n - (4 - i), 4 - i);

            if (init + end == year) possible = true;
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
}