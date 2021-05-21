#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;

        int idx = 0;
        string ans(1, s[0]);
        bool possible = true;

        for (int i = 1; i < size(s) && possible; i++) {
            if (idx > 0 && ans[idx - 1] == s[i]) idx--;
            else if (idx + 1 < size(ans) && ans[idx + 1] == s[i]) idx++;
            else if (idx == size(ans) - 1) ans += s[i], idx++;
            else if (idx == 0) ans = string(1, s[i]) + ans;
            else possible = false;
        }

        int cnt[30] = {0};
        for (int i = 0; i < size(ans) && possible; i++)
            if (++cnt[ans[i] - 'a'] > 1) possible = false;

        if (!possible) cout << "NO\n";
        else {
            for (char c = 'a'; c <= 'z'; c++)
                if (!cnt[c - 'a']) ans += c;

            cout << "YES\n" << ans << "\n";
        }
    }
}