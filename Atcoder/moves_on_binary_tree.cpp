#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; long X;
    cin >> N >> X;

    string S; cin >> S;

    stack<char> ops;
    for (char op: S) {
        if (op == 'L' || op == 'R') ops.push(op);
        else if (ops.empty()) X /= 2LL;
        else ops.pop();
    }

    vector<char> rem;
    while (!ops.empty()) {
        rem.push_back(ops.top());
        ops.pop();
    }

    reverse(rem.begin(), rem.end());

    for (char op: rem) {
        X *= 2LL;
        if (op == 'R')
            X++;
    }

    cout << X << "\n";
}