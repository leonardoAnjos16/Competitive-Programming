#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> colors(n);
        int balance = 0, normal = 0, reversed = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && balance < 0) reversed++, balance++, colors[i] = 2;
            else if (s[i] == ')' && balance > 0) normal++, balance--, colors[i] = 1;
            else if (s[i] == '(') balance++, colors[i] = 1;
            else balance--, colors[i] = 2;
        }

        if (balance) cout << "-1\n";
        else {
            if (normal && reversed) cout << "2\n";
            else {
                cout << "1\n";
                if (reversed)
                    for (int i = 0; i < n; i++)
                        colors[i] = 1;
            }

            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << colors[i];
            }

            cout << "\n";
        }
    }
}