#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> stacks[2];
    vector<int> which(n + 1, -1);

    int curr = 1;
    for (int i = 0; i < n; i++) {
        cout << "1\n";
        stacks[0].push(a[i]);
        which[a[i]] = 0;

        while (curr <= n && which[curr] != -1) {
            while (stacks[which[curr]].top() != curr) {
                cout << (which[curr] ? "21" : "12") << "\n";
                which[stacks[which[curr]].top()] = 1 - which[curr];
                stacks[1 - which[curr]].push(stacks[which[curr]].top());
                stacks[which[curr]].pop();
            }

            cout << -(which[curr] + 1) << "\n";
            stacks[which[curr]].pop();
            which[curr++] = -1;
        }
    }

    assert(curr > n);
}