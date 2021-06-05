#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int smileys = 0, frowneys = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ':') {
            if (i > 0) {
                if (s[i - 1] == '(') smileys++;
                else if (s[i - 1] == ')') frowneys++;
            }

            if (i + 1 < n) {
                if (s[i + 1] == ')') smileys++;
                else if (s[i + 1] == '(') frowneys++;
            }
        }
    }

    if (smileys > frowneys) cout << "HAPPY\n";
    else if (smileys < frowneys) cout << "SAD\n";
    else cout << "BORED\n";
}