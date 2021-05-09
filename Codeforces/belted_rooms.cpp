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

const int MAX = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt[2] = {0};
        for (int i = 0; i < n; i++) {
            if (s[i] == '<') cnt[0]++;
            else if (s[i] == '>') cnt[1]++;
        }

        if (!cnt[0] || !cnt[1]) cout << n << "\n";
        else {
            bitset<MAX> returnable;
            for (int i = 0; i < n; i++)
                if (s[i] == '-') {
                    returnable[i] = true;
                    returnable[(i + 1) % n] = true;
                }

            int ans = 0;
            for (int i = 0; i < n; i++)
                if (returnable[i]) ans++;

            cout << ans << "\n";
        }
    }
}