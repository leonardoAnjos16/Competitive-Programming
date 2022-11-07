#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x, y;
        string z;
        cin >> x >> y >> z;

        reverse(z.begin(), z.end());
        long long int num = 0LL, pow = 1LL;

        for (char c: z) {
            int d = c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10;
            num += d * pow;
            pow *= x;
        }

        // cout << num << "\n";

        string ans = "";
        while (num) {
            int d = num % y;
            num /= y;

            char c = d < 10 ? '0' + d : 'A' + d - 10;
            ans += c;
        }

        reverse(ans.begin(), ans.end());
        if (ans.empty()) ans = "0";
        cout << ans << "\n";
    }
}