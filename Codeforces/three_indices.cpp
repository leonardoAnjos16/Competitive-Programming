#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        stack<int> aux;
        vector<int> nxt(n, -1);

        for (int i = 0; i < n; i++) {
            while (!aux.empty() && p[aux.top()] > p[i]) {
                nxt[aux.top()] = i;
                aux.pop();
            }

            aux.push(i);
        }

        while (!aux.empty()) aux.pop();

        vector<int> prev(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!aux.empty() && p[aux.top()] > p[i]) {
                prev[aux.top()] = i;
                aux.pop();
            }

            aux.push(i);
        }

        int a = -1, b = -1, c = -1;
        for (int i = 0; i < n && a == -1; i++)
            if (prev[i] != -1 && nxt[i] != -1) {
                a = prev[i] + 1;
                b = i + 1;
                c = nxt[i] + 1;
            }

        if (a == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        }
    }
}