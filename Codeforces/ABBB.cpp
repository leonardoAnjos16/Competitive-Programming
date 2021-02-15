#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        stack<char> aux;
        for (auto c: s) {
            if (c == 'B' && !aux.empty()) aux.pop();
            else aux.push(c);
        }

        int ans = (int) aux.size();
        cout << ans << "\n";
    }
}