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

const int MAX_M = 205;
const int MAX_C = 25;

int M, C;
vi g[MAX_C];
int memo[MAX_M][MAX_C];

int money(int m = 0, int i = 0) {
    if (m > M) return -1;
    if (i >= C) return m;

    int &ans = memo[m][i];
    if (~ans) return ans;

    ans = INT_MIN;
    for (auto price: g[i])
        ans = max(ans, money(m + price, i + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--) {
        cin >> M >> C;
        for (int i = 0; i < C; i++) {
            int K; cin >> K;
            g[i].assign(K, 0);

            for (int j = 0; j < K; j++)
                cin >> g[i][j];
        }

        memset(memo, -1, sizeof memo);

        int ans = money();
        if (ans == -1)
            cout << "no solution\n";
        else
            cout << ans << "\n";
    }
}