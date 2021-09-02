#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool isRXCY(string &s) {
    if (s[0] != 'R') return false;
    if (s[1] < '0' || s[1] > '9') return false;

    int idx = 2;
    while (idx < (int) s.size() && s[idx] != 'C')
        idx++;

    if (idx == 1 || idx >= (int) s.size())
        return false;

    return true;
}

int CRtoRXCY(string &col) {
    int ans = 0;
    for (char c: col) {
        ans *= 26;
        ans += c - 'A' + 1;
    }

    return ans;
}

string RXCYtoCR(int col) {
    string ans = "";
    while (--col >= 0) {
        int d = col % 26;
        char c = 'A' + d;
        ans += c;
        col /= 26;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (isRXCY(s)) {
            int idx = 1;
            string row = "";

            while (s[idx] != 'C')
                row += s[idx++];

            idx++;
            string col = "";

            while (idx < (int) s.size())
                col += s[idx++];

            string ans = RXCYtoCR(stoi(col)) + row;
            cout << ans << "\n";
        } else {
            string row = "", col = "";
            for (char c: s) {
                if (c >= 'A' && c <= 'Z') col += c;
                else row += c;
            }

            string ans = "R" + row + "C" + to_string(CRtoRXCY(col));
            cout << ans << "\n";
        }
    }
}