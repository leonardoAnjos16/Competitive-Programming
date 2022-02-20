#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;
    bool inv = false;

    int Q; cin >> Q;
    while (Q--) {
        string op; cin >> op;
        if (op == "reverse") inv = !inv;
        else if (op == "back") {
            if (dq.empty()) cout << "No job for Ada?\n";
            else if (inv) cout << dq.front() << "\n", dq.pop_front();
            else cout << dq.back() << "\n", dq.pop_back();
        } else if (op == "front") {
            if (dq.empty()) cout << "No job for Ada?\n";
            else if (inv) cout << dq.back() << "\n", dq.pop_back();
            else cout << dq.front() << "\n", dq.pop_front();
        } else if (op == "push_back") {
            int N; cin >> N;
            if (inv) dq.push_front(N);
            else dq.push_back(N);
        } else {
            int N; cin >> N;
            if (inv) dq.push_back(N);
            else dq.push_front(N);
        }
    }
}