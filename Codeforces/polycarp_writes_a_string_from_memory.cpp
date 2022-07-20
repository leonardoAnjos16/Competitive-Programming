#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        int ans = 0, idx = 0;
        while (idx < n) {
            int cnt = 0;
            bool used[MAX] = {0};

            while (idx < n && cnt <= 3) {
                if (used[s[idx] - 'a']) idx++;
                else used[s[idx++] - 'a'] = true, cnt++;
            }

            ans++;
            if (cnt > 3) idx--;
        }

        cout << ans << "\n";
    }
}