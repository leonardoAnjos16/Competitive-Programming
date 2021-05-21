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
const long INF = 2e18;

struct FenwickTree {
private:
    long tree[MAX];

public:
    FenwickTree() {
        memset(tree, 0, sizeof tree);
    }

    void add(int i, int x) {
        if (!i) tree[i] += x;
        else {
            while (i < MAX) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    long sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long sum(int i) {
        if (i < 0) return 0;

        long ans = 0LL;
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

    int q, n;
    cin >> q >> n;

    vector<tuple<int, long, long>> queries;
    vector<long> ks;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int id; long x;
            cin >> id >> x;
            queries.pb({ op, id, x });
        } else {
            long k; cin >> k;
            queries.pb({ op, k, 0LL });
            ks.pb(k);
        }
    }

    ks.pb(INF);
    sort(all(ks));

    FenwickTree tree;
    tree.add(0, n);

    long cnt[MAX] = {0};
    for (auto t: queries) {
        int x; long y, z;
        tie(x, y, z) = t;

        if (x == 1) {
            int idx = lb(all(ks), cnt[y]) - ks.begin();
            tree.add(idx, -1);
            cnt[y] += z;

            idx = lb(all(ks), cnt[y]) - ks.begin();
            tree.add(idx, 1);
        } else {
            int idx = ub(all(ks), y) - ks.begin();
            long ans = tree.sum(idx, MAX - 1);
            cout << ans << "\n";
        }
    }
}