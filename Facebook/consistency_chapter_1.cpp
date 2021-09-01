#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool vowel(char c) {
    switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string S; cin >> S;
        int N = S.size();

        int ans = INT_MAX;
        for (char c = 'A'; c <= 'Z'; c++) {
            int cost = 0;
            for (int i = 0; i < N; i++)
                if (S[i] != c)
                    cost += vowel(c) != vowel(S[i]) ? 1 : 2;

            ans = min(ans, cost);
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}