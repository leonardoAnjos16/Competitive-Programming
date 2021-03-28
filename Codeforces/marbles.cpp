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

const long INF = 1e18;
const int MAX = 4e5 + 5;

vi indices[25];
set<int> colors;

long memo[1 << 20];
long front[25][25];

long swaps(int used = 0) {
    int aux = 0;
    for (int i = 0; i < 20; i++)
        if (used & (1 << i)) aux++;

    if (aux == size(colors)) return 0LL;

    long &ans = memo[used];
    if (~ans) return ans;

    ans = INF;
    for (auto c: colors) {
        if (!(used & (1 << c))) {
            long sum = 0LL;
            for (auto d: colors)
                if (used & (1 << d)) {
                    if (front[c][d] == -1) {
                        front[c][d] = 0LL;
                        for (auto i: indices[c]) {
                            int left = upper_bound(all(indices[d]), i) - indices[d].begin();
                            front[c][d] += size(indices[d]) - left;
                        }
                    }

                    sum += front[c][d];
                }

            ans = min(ans, sum + swaps(used | (1 << c)));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        indices[a - 1].pb(i);
        colors.insert(a - 1);
    }

    memset(memo, -1, sizeof memo);
    memset(front, -1, sizeof front);

    long ans = swaps();
    cout << ans << "\n";
}