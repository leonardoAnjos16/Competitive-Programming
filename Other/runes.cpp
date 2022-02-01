#include <bits/stdc++.h>

using namespace std;

#define long long long int

tuple<string, char, string, string> parse(string s) {
    int idx = 0;
    string first_operand = "";

    if (s[idx] == '-') first_operand += s[idx++];

    while (s[idx] != '+' && s[idx] != '-' && s[idx] != '*')
        first_operand += s[idx++];

    char operation = s[idx++];

    string second_operand = "";
    while (s[idx] != '=')
        second_operand += s[idx++];

    string result = "";
    while (++idx < (int) s.size())
        result += s[idx];

    return make_tuple(first_operand, operation, second_operand, result);
}

long substitute(string s, int d) {
    for (int i = 0; i < (int) s.size(); i++)
        if (s[i] == '?') s[i] = '0' + d;

    return stoll(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        auto [first_operand, operation, second_operand, result] = parse(s);

        bool used[10] = {0};
        for (int i = 0; i < (int) s.size(); i++)
            if (s[i] >= '0' && s[i] <= '9')
                used[s[i] - '0'] = true;

        int ans = 0;
        if (first_operand[0] == '?' && (int) first_operand.size() > 1) ans = 1;
        else if (first_operand[0] == '-' && first_operand[1] == '?') ans = 1;

        if (second_operand[0] == '?' && (int) second_operand.size() > 1) ans = 1;
        else if (second_operand[0] == '-' && second_operand[1] == '?') ans = 1;

        if (result[0] == '?' && (int) result.size() > 1) ans = 1;
        else if (result[0] == '-' && result[1] == '?') ans = 1;

        bool done = false;
        while (ans < 10 && !done) {
            if (used[ans]) {
                ans++;
                continue;
            }
            
            long a = substitute(first_operand, ans);
            long b = substitute(second_operand, ans);
            long c = substitute(result, ans);

            if (operation == '+' && a + b == c) done = true;
            else if (operation == '-' && a - b == c) done = true;
            else if (operation == '*' && a * b == c) done = true;
            else ans++;
        }

        if (!done) cout << "-1\n";
        else cout << ans << "\n";
    }
}