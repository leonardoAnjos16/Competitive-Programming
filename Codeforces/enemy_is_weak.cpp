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

const int MAX = 2e5 + 5;
const int INF = 2e9 + 5;

struct FenwickTree {
private:
    int n;
    vi tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i < n) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

    void clear() {
        tree.assign(n, 0);
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

    vi a(n), values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }

    sort(all(values));

    vi greater(n);
    FenwickTree tree(size(values));

    for (int i = 0; i < n; i++) {
        int idx = lb(all(values), a[i]) - values.begin() + 1;
        greater[i] = tree.sum(min(idx + 1, size(values)), size(values));
        tree.add(idx, 1);
    }

    vi lesser(n);
    tree.clear();

    for (int i = n - 1; i >= 0; i--) {
        int idx = lb(all(values), a[i]) - values.begin() + 1;
        lesser[i] = tree.sum(1, max(idx - 1, 1));
        tree.add(idx, 1);
    }

    long ans = 0LL;
    for (int i = 0; i < n; i++)
        ans += 1LL * greater[i] * lesser[i];

    cout << ans << "\n";
}