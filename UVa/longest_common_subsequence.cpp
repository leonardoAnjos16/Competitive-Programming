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

string s, t;
int memo[MAX][MAX];

int LCS(int i = 0, int j = 0) {
    if (i >= size(s) || j >= size(t)) return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = max(LCS(i + 1, j), LCS(i, j + 1));
    if (s[i] == t[j]) ans = max(ans, 1 + LCS(i + 1, j + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, s) && getline(cin, t)) {
        memset(memo, -1, sizeof memo);

        int ans = LCS();
        cout << ans << "\n";
    }
}