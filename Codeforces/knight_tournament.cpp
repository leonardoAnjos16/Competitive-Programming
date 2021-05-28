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

const int MAX = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> ids;
    for (int i = 1; i <= n; i++)
        ids.insert(i);

    int ans[MAX] = {0};
    while (m-- && !ids.empty()) {
        int l, r, x;
        cin >> l >> r >> x;

        auto start = ids.lb(l);
        auto end = ids.ub(r);

        for (auto it = start; it != end; it++)
            if (*it != x) ans[*it] = x;

        ids.erase(start, end);
        ids.insert(x);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}