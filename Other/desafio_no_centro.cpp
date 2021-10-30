#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string ans = "1";
    while (--n) {
        int cnt = 1;
        string curr = "";

        for (int i = 1; i < (int) ans.size(); i++) {
            if (ans[i] == ans[i - 1]) cnt++;
            else {
                curr += to_string(cnt) + ans[i - 1];
                cnt = 1;
            }
        }

        curr += to_string(cnt) + ans.back();
        ans = curr;
    }

    cout << ans << "\n";
}