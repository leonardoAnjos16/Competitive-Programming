#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string a; cin >> a;

        bool possible = false;
        for (int i = 0; i < (1 << 3) && !possible; i++) {
            char A = i & (1 << 0) ? '(' : ')';
            char B = i & (1 << 1) ? '(' : ')';
            char C = i & (1 << 2) ? '(' : ')';

            string curr = "";
            for (char c: a) {
                if (c == 'A') curr += A;
                else if (c == 'B') curr += B;
                else curr += C;
            }

            stack<char> aux;
            possible = true;

            for (char c: curr) {
                if (c == '(') aux.push(c);
                else if (!aux.empty()) aux.pop();
                else {
                    possible = false;
                    break;
                }
            }

            possible &= aux.empty();
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}