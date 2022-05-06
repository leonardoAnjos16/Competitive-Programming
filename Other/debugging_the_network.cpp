#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string S; int K;
        cin >> S >> K;

        int n = S.size();

        string ans = "";
        int sum = 0, idx = 0;
        bool possible = true;

        while (idx < n && possible) {
            string number = "";
            while (idx < n && S[idx] >= '0' && S[idx] <= '9')
                number += S[idx++];

            if ((int) number.size() > 7) possible = false;
            else {
                if (number.empty()) number = "1";

                int repeat = stoi(number);
                if (sum + repeat > K) possible = false;
                else {
                    sum += repeat;
                    ans += string(repeat, S[idx++]);
                }
            }
        }

        if (!possible) cout << "unfeasible\n";
        else cout << ans << "\n";
    }
}