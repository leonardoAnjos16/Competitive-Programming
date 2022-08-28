#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<bool> value(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        value[i] = c == 'T';
    }

    char c;
    stack<bool> aux;

    while (cin >> c) {
        if (c >= 'A' && c <= 'Z') aux.push(value[c - 'A']);
        else if (c == '-') {
            bool ntop = !aux.top(); aux.pop();
            aux.push(ntop);
        }
        else {
            bool top = aux.top(); aux.pop();
            bool stop = aux.top(); aux.pop();
            aux.push(c == '*' ? top && stop : top || stop);
        }
    }

    assert((int) aux.size() == 1);

    char ans = aux.top() ? 'T' : 'F';
    cout << ans << "\n";
}