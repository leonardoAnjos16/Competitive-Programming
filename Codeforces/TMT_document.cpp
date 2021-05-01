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
        int n; cin >> n;
        string s; cin >> s;

        vi Ts, Ms;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T') Ts.pb(i);
            else Ms.pb(i);
        }

        int idx = 0;
        bool possible = true;

        for (int i = 0; i < size(Ms) && possible; i++)
            if (idx >= size(Ts) || Ts[idx++] > Ms[i])
                possible = false;

        for (int i = 0; i < size(Ms) && possible; i++)
            if (idx >= size(Ts) || Ts[idx++] < Ms[i])
                possible = false;

        if (!possible) cout << "NO\n";
        else if (idx >= size(Ts)) cout << "YES\n";
        else cout << "NO\n";
    }
}