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

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int diff[MAX] = {0};
    for (int i = 2; i < MAX; i++)
        if (!diff[i])
            for (int j = i; j < MAX; j += i)
                diff[j]++;

    map<int, vi> indices;
    for (int i = 1; i < MAX; i++)
        indices[diff[i]].pb(i);

    int T; cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;

        int ans = ub(all(indices[n]), b) - lb(all(indices[n]), a);
        cout << ans << "\n";
    }
}