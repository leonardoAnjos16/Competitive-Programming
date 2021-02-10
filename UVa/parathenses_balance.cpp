#include <bits/stdc++.h>

using namespace std;

const int MAX = 200;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cin.ignore();
    
    while (n--) {
        string s; getline(cin, s);
        stack<char> aux;

        for (int i = 0; i < (int) s.size(); i++) {
            char top;
            if (aux.empty()) top = '-';
            else top = aux.top();

            if ((top == '(' && s[i] == ')') || (top == '[' && s[i] == ']')) aux.pop();
            else aux.push(s[i]);
        }

        if (!aux.empty()) cout << "No\n";
        else cout << "Yes\n";
    }
}