#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n) {
        vector<int> trucks(n);
        for (int i = 0; i < n; i++)
            cin >> trucks[i];

        stack<int> s;
        queue<int> q;

        int expected = 1;
        for (int i = 0; i < n; i++) {
            if (trucks[i] == expected) q.push(trucks[i]), expected++;
            else {
                while (!s.empty() && s.top() < trucks[i])
                    q.push(s.top()), s.pop();

                s.push(trucks[i]);
            }
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        expected = 1;
        bool possible = true;

        assert((int) q.size() == n);
        while (!q.empty() && possible) {
            if (q.front() != expected) possible = false;
            else q.pop(), expected++;
        }

        cout << (possible ? "yes" : "no") << "\n";
    }
}