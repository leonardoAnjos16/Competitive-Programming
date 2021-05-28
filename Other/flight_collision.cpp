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

const int MAX = 1e5 + 5;

struct cmp {
    bool operator() (pair<pll, pii> &a, pair<pll, pii> &b) {
        long na = a.fst.fst, da = a.fst.snd;
        long nb = b.fst.fst, db = b.fst.snd;
        return na * db > nb * da;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    pll drones[MAX];
    for (int i = 0; i < n; i++) {
        long x, v;
        cin >> x >> v;
        drones[i] = { x, v };
    }

    priority_queue<pair<pll, pii>, vector<pair<pll, pii>>, cmp> pq;
    for (int i = 1; i < n; i++) {
        long num = drones[i].fst - drones[i - 1].fst;
        long den = drones[i - 1].snd - drones[i].snd;
        if (den && num / abs(num) == den / abs(den))
            pq.emplace(mp(num, den), mp(i - 1, i));
    }

    int left[MAX], right[MAX];
    for (int i = 0; i < n; i++)
        left[i] = i - 1, right[i] = i + 1;

    bitset<MAX> fallen;
    while (!pq.empty()) {
        pii chosen = pq.top().snd; pq.pop();
        int l = chosen.fst, r = chosen.snd;

        if (fallen[l] || fallen[r]) continue;
        fallen[l] = fallen[r] = true;

        int ll = left[l], rr = right[r];
        if (ll < 0 || rr >= n) continue;

        left[rr] = ll;
        right[ll] = rr;

        long num = drones[rr].fst - drones[ll].fst;
        long den = drones[ll].snd - drones[rr].snd;
        if (den && num / abs(num) == den / abs(den))
            pq.emplace(mp(num, den), mp(ll, rr));
    }

    vi ans;
    for (int i = 0; i < n; i++)
        if (!fallen[i]) ans.pb(i + 1);

    cout << size(ans) << "\n";
    for (int i = 0; i < size(ans); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}