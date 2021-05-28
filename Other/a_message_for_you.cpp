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

const int MAX = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("scoreboard.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        string s; cin >> s;

        pair<int, char> t[MAX];
        for (int i = 0; i < 13; i++) {
            int v; cin >> v;
            t[i] = { v, i + 'A' };
        }

        sort(t, t + 13, greater<pair<int, char>>());

        bool done = false;
        for (int i = 0; i < 13 && !done; i++) {
            char c = t[i].snd;
            if (!binary_search(all(s), c)) {
                cout << c << "\n";
                done = true;
            }
        }
    }
}