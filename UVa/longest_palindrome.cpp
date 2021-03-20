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

string s;
int memo[MAX][MAX];

int LP(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = max(LP(i + 1, j), LP(i, j - 1));
    if (s[i] == s[j]) ans = max(ans, 2 + LP(i + 1, j - 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    cin.ignore();

    while (T--) {
        getline(cin, s);
        memset(memo, -1, sizeof memo);

        int ans = LP(0, size(s) - 1);
        cout << ans << "\n";
    }
}