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

int A[MAX];
vector<vi> g;

int memo[MAX][2];

int profit(int v, int bought = 0) {
    if (!size(g[v])) return bought ? A[v] : INT_MIN;

    int &ans = memo[v][bought];
    if (~ans) return ans;

    ans = INT_MIN;

    if (bought) ans = A[v];
    for (auto u: g[v]) {    
        ans = max(ans, profit(u, bought));
        if (!bought) ans = max(ans, profit(u, 1) - A[v]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    g.assign(N, vi());
    while (M--) {
        int X, Y;
        cin >> X >> Y;
        g[--X].pb(--Y);
    }

    memset(memo, -1, sizeof memo);

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        ans = max(ans, profit(i));

    cout << ans << "\n";
}