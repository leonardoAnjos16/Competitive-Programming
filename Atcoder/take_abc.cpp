#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;

    int idx = 0;
    char nxt = 'A';

    string ans = "";
    while (idx < (int) S.size()) {
        ans += S[idx];

        if (S[idx] == nxt) nxt++;
        else if (S[idx] == 'A') nxt = 'B';
        else nxt = 'A';

        if (nxt > 'C') {
            for (int i = 0; i < 3; i++)
                ans.pop_back();

            if (ans.empty()) nxt = 'A';
            else if ((int) ans.size() == 1) nxt = ans.back() == 'A' ? 'B' : 'A';
            else if (ans[(int) ans.size() - 2] == 'A' && ans.back() == 'B') nxt = 'C';
            else if (ans.back() == 'A') nxt = 'B';
            else nxt = 'A';
        }

        idx++;
    }

    cout << ans << "\n";
}