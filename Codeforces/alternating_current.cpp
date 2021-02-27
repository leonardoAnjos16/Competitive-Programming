#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    stack<char> aux;

    for (char c: s) {
        if (!aux.empty() && c == aux.top()) aux.pop();
        else aux.push(c);
    }

    cout << (aux.empty() ? "Yes" : "No") << "\n";
}