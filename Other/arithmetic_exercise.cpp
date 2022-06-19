#include <bits/stdc++.h>

using namespace std;

void round_up(string &num, int i) {
    while (num[i] != '.' && num[i] == '9')
        num[i--] = '0';

    if (num[i] != '.') num[i]++;
    else num[i - 1]++;
}

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    if (A == B) cout << "1." << string(K, '0') << "\n";
    else {
        int digits = 0;
        string ans = "0.";

        while (A && digits < K + 1) {
            A *= 10;
            while (A < B) {
                digits++;
                ans += "0";
                A *= 10;
            }

            int digit = A / B;
            ans += (char) ('0' + digit);
            digits++;
            A %= B;
        }

        while ((int) ans.size() < K + 3)
            ans += "0";

        if (ans[K + 2] >= '5') round_up(ans, K + 1);
        ans = ans.substr(0, K + 2);
        cout << ans << "\n";
    }
}