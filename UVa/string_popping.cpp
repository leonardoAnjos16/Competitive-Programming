#include <bits/stdc++.h>

using namespace std;

set<string> memo;

bool possible(string str) {
    if (str == "" || memo.count(str)) return true;

    bool ans = false;
    int i = 0, j = 0;

    while (i < (int) str.size() && !ans) {
        j = i + 1;
        while (j < (int) str.size() && str[j] == str[i]) j++;
        if (j - i > 1) ans |= possible(str.substr(0, i) + str.substr(j));
        i = j;
    }

    if (ans) memo.insert(str);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        cout << (possible(str) ? 1 : 0) << "\n";
    }
}