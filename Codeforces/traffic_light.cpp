#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; char c;
        cin >> n >> c;

        string s; cin >> s;
        s += s;

        stack<int> aux;
        vector<int> nxt(2 * n, -1);

        for (int i = 0; i < 2 * n; i++) {
            if (s[i] != 'g') aux.push(i);
            else {
                while (!aux.empty()) {
                    nxt[aux.top()] = i;
                    aux.pop();
                }
            }
        }

        if (c == 'g') cout << "0\n";
        else {
            int ans = INT_MIN;
            for (int i = 0; i < 2 * n; i++)
                if (s[i] == c && nxt[i] != -1)
                    ans = max(ans, nxt[i] - i);

            cout << ans << "\n";
        }
    }
}