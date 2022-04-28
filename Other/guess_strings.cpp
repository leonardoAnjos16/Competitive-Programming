#include <bits/stdc++.h>

using namespace std;

#define long long long int

set<string> asked;

bool is_substr(string s) {
    if (!asked.count(s)) {
        asked.insert(s);
        cout << "ASK " << s << "\n";
        cout.flush();

        int ans;
        cin >> ans;
        return ans;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string letters = "";
    for (char c = 'a'; c <= 'z' && (int) letters.size() < 2; c++)
        if (is_substr(string(1, c)))
            letters += c;

    bool end = false, assumed = false;
    string a(1, letters[0]), b(1, letters[1]), ans = a;

    while (!end) {
        if (is_substr(ans + a)) ans += a, assumed = false;
        else if (!assumed) ans += b, assumed = true;
        else if (is_substr(ans + b)) ans += b, assumed = false;
        else if (is_substr(ans)) end = true;
        else ans.pop_back(), end = true;
    }

    end = false; assumed = false;
    while (!end) {
        if (is_substr(a + ans)) ans = a + ans, assumed = false;
        else if (!assumed) ans = b + ans, assumed = true;
        else if (is_substr(b + ans)) ans = b + ans, assumed = false;
        else if (is_substr(ans)) end = true;
        else ans = ans.substr(1), end = true;
    }

    cout << "ANSWER " << ans << "\n";
    cout.flush();
}