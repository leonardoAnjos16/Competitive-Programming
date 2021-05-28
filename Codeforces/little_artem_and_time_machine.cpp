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

struct FenwickTree {
private:
    int n;
    vi tree;

public:
    void init(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i <= n) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans + tree[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<int, vi> times;
    tuple<int, int, int> queries[MAX];

    for (int i = 0; i < n; i++) {
        int a, t, x;
        cin >> a >> t >> x;

        times[x].pb(t);
        queries[i] = { a, t, x };
    }

    map<int, FenwickTree> trees;
    for (auto &p: times) {
        sort(all(p.snd));
        trees[p.fst].init(size(p.snd));
    }

    for (int i = 0; i < n; i++) {
        int a, t, x;
        tie(a, t, x) = queries[i];

        int idx = lb(all(times[x]), t) - times[x].begin();
        if (a == 1) trees[x].add(idx, 1);
        else if (a == 2) trees[x].add(idx, -1);
        else {
            int ans = trees[x].sum(0, idx);
            cout << ans << "\n";
        }
    }
}