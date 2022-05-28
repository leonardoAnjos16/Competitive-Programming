#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    stack<int> aux;
    vector<int> next(n, n - 1);

    for (int i = 0; i < n; i++) {
        while (!aux.empty() && s[aux.top()] < s[i])
            next[aux.top()] = i - 1, aux.pop();

        aux.push(i);
    }

    while (!aux.empty()) aux.pop();
    vector<int> prev(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while (!aux.empty() && s[aux.top()] < s[i])
            prev[aux.top()] = i + 1, aux.pop();

        aux.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        long ans = (i - prev[i] + 1LL) * (next[i] - i + 1LL);
        cout << ans;
    }

    cout << "\n";
}