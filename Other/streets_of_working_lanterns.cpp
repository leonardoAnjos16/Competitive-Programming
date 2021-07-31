#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    if (n & 1) cout << "Impossible\n";
    else {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '(') cnt++;

        for (int i = 0; i < n; i++)
            if (s[i] == '?') {
                s[i] = cnt < n / 2 ? '(' : ')';
                if (s[i] == '(') cnt++;
            }

        stack<char> aux;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            if (s[i] == '(') aux.push('(');
            else if (aux.empty()) possible = false;
            else aux.pop();
        }

        possible &= aux.empty();
        cout << (possible ? s : "Impossible") << "\n";
    }
}