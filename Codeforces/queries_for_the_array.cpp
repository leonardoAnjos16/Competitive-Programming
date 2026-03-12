#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        vector<int> info;
        bool possible = true;

        for (int i = 0; i < (int) s.size() && possible; i++) {
            if (s[i] == '1' && !info.empty() && info.back() == 0) possible = false;
            else if (s[i] == '0' && (info.empty() || info.back() == 1)) possible = false;
            else if ((s[i] == '0' || s[i] == '1') && !info.empty()) info.back() = s[i] - '0';
            else if (s[i] == '-') {
                int last = info.back();
                info.pop_back();

                if (last == 1 && !info.empty())
                    info.back() = 1;
            }
            else if (s[i] == '+') {
                if (info.empty()) info.push_back(1);
                else if (info.back() == 0) info.push_back(0);
                else info.push_back(-1);
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}