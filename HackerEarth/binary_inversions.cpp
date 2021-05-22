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

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a; long x;
    cin >> n >> a >> x;

    bool possible = true;
    int ans[MAX], b = n - a;

    for (int i = 0; i < n && possible; i++) {
        if (a && b * (a - 1LL) >= x) ans[i] = 0, a--;
        else if (b) ans[i] = 1, x -= a, b--;
        else possible = false;
    }

    if (!possible) cout << "-1\n";
    else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}