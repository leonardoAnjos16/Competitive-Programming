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

const int MAX = 1e3 + 5;

int X, Y;
string S;

int memo[MAX][10];

int price(int i, int last, int chosen) {
    if (!i) return 0;
    return last < chosen ? X : (last > chosen ? Y : 0);
}

int cost(int i = 0, int last = 0) {
    if (i >= size(S)) return 0;

    int &ans = memo[i][last];
    if (~ans) return ans;

    if (S[i] != '?') return ans = price(i, last, S[i] == 'J') + cost(i + 1, S[i] == 'J');
    return ans = min(price(i, last, 0) + cost(i + 1, 0), price(i, last, 1) + cost(i + 1, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> X >> Y >> S;
        memset(memo, -1, sizeof memo);

        int ans = cost();
        cout << "Case #" << t << ": " << ans << "\n";
    }
}