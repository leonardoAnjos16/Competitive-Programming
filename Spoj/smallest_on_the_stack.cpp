#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    stack<int> pile;
    while (N--) {
        string op; cin >> op;
        if (op == "PUSH") {
            int V; cin >> V;
            if (!pile.empty() && pile.top() < V)
                V = pile.top();

            pile.push(V);
        } else if (op == "POP") {
            if (pile.empty()) cout << "EMPTY\n";
            else pile.pop();
        } else {
            if (pile.empty()) cout << "EMPTY\n";
            else cout << pile.top() << "\n";
        }
    }
}