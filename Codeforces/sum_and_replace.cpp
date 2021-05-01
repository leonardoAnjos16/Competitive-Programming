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

const int MAX_A = 1e6 + 5;
const int MAX_N = 3e5 + 5;

struct FenwickTree {
private:
    long tree[MAX_N];

public:
    FenwickTree() {
        memset(tree, 0, sizeof tree);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i < MAX_N) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long sum(int i) {
        if (i < 0) return 0;

        long sum = 0LL;
        while (i > 0) {
            sum += tree[i];
            i -= LSO(i);
        }

        return sum + tree[0];
    }
};

int a[MAX_N], D[MAX_A];

int count_divisors(int n) {
    if (~D[n]) return D[n];

    int ans = 1;
    for (long i = 2; i * i <= n; i++) {
        int cnt = 1;
        while (!(n % i))
            cnt++, n /= i;

        ans *= cnt;
    }

    if (n > 1) ans *= 2;
    return ans;
}

void update(FenwickTree &tree, FenwickTree &cnt, int l, int r) {
    if (!cnt.sum(l, r)) return;

    if (l == r) {
        D[a[l - 1]] = count_divisors(a[l - 1]);
        tree.add(l, D[a[l - 1]] - a[l - 1]);

        a[l - 1] = D[a[l - 1]];
        if (a[l - 1] <= 2) cnt.add(l, -1);
    } else {
        int mid = (l + r) / 2;
        update(tree, cnt, l, mid);
        update(tree, cnt, mid + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(D, -1, sizeof D);

    int n, m;
    cin >> n >> m;

    FenwickTree tree, cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tree.add(i + 1, a[i]);
        if (a[i] > 2) cnt.add(i + 1, 1);
    }

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) update(tree, cnt, l, r);
        else {
            long ans = tree.sum(l, r);
            cout << ans << "\n";
        }
    }
}