#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        string s; cin >> s;
        bool possible = true;

        int cnt[2] = {0}, n = a + b;
        for (int i = 0; i < n / 2 && possible; i++) {
            if (s[i] == '?' && s[n - i - 1] != '?') s[i] = s[n - i - 1], cnt[s[i] - '0'] += 2;
            else if (s[i] != '?' && s[n - i - 1] == '?') s[n - i - 1] = s[i], cnt[s[i] - '0'] += 2;
            else if (s[i] != '?' && s[n - i - 1] != '?' && s[i] == s[n - i - 1]) cnt[s[i] - '0'] += 2;
            else if (s[i] != '?' && s[n - i - 1] != '?') possible = false;
        }

        if (n & 1 && s[n / 2] != '?') cnt[s[n / 2] - '0']++;

        a -= cnt[0]; b -= cnt[1];
        if (a < 0 || b < 0) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < n / 2 && possible; i++) {
            if (s[i] == '?') {
                if (a >= 2) s[i] = s[n - i - 1] = '0', a -= 2;
                else if (b >= 2) s[i] = s[n - i - 1] = '1', b -= 2;
                else possible = false;
            }
        }

        if (possible && n & 1 && (s[n / 2] == '?')) {
            if (a) s[n / 2] = '0';
            else if (b) s[n / 2] = '1';
            else possible = false;
        }

        if (!possible) cout << "-1\n";
        else cout << s << "\n";
    }
}