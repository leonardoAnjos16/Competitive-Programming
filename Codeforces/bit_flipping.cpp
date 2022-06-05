#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s; cin >> s;

        int cnt = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && (k & 1)) ans[i] = 1, cnt++;
            else if (s[i] == '0' && !(k & 1)) ans[i] = 1, cnt++;
        }

        if (cnt > k)
            for (int i = n - 1; i >= 0 && cnt > k; i--)
                if (ans[i]) ans[i] = 0, cnt--;
        else if (!((k - cnt) & 1)) ans[0] += k - cnt;
        else ans[0] += k - cnt - 1, ans[n - 1]++;

        for (int i = 0; i < n; i++)
            if ((k - ans[i]) & 1)
                s[i] = '0' + (1 - (s[i] - '0'));

        cout << s << "\n";
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}