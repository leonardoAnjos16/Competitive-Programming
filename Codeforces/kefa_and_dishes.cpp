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

const int MAX = 25;

int n, m, a[MAX];
map<pii, int> rules;

long memo[MAX][1 << 18];

long satisfaction(int last = 0, int used = 0) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used & (1 << i)) cnt++;

    if (cnt == m) return 0LL;

    long &ans = memo[last][used];
    if (~ans) return ans;

    for (int i = 0; i < n; i++)
        if (!(used & (1 << i)))
            ans = max(ans, satisfaction(i + 1, used | (1 << i)) + a[i] + rules[{ last, i + 1 }]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (k--) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[{ x, y }] = c;
    }

    memset(memo, -1, sizeof memo);

    long ans = satisfaction();
    cout << ans << "\n";
}