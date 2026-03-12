#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 22;

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int last(int i) {
        int s = -sum(i - 1), ans = 0;
        for (int j = LOG; j >= 0; j--) {
            int nans = ans + (1 << j);
            if (nans < n && s + tree[nans] >= nans - i + 1) {
                ans = nans;
                s += tree[nans];
            }
        }

        return ans;
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int n;
vector<vector<int>> nxt, pos;
vector<vector<llong>> memo;

llong shifts(bool last, int i) {
    if (i > n) return 0LL;

    llong &ans = memo[last][i];
    if (~ans) return ans;

    int to = nxt[last][i];
    int dist = to > n ? 0 : abs(pos[last][i] - pos[0][to]);
    if (to <= n && n - dist < dist) dist = n - dist;

    ans = shifts(false, to) + dist;

    dist = to > n ? 0 : abs(pos[last][i] - pos[1][to]);
    if (to <= n && n - dist < dist) dist = n - dist;

    ans = min(ans, shifts(true, to) + dist);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        FenwickTree tree(n);
        for (int i = 0; i < k; i++)
            tree.add(a[i], 1);

        int first = tree.last(1) + 1;
        nxt.assign(2, vector<int>(n + 1));
        pos.assign(2, vector<int>(n + 1));

        for (int i = 0; i < n; i++) {
            nxt[0][a[i]] = tree.last(a[i]) + 1;
            nxt[1][a[(i + k - 1) % n]] = tree.last(a[(i + k - 1) % n]) + 1;
            pos[0][a[i]] = pos[1][a[(i + k - 1) % n]] = i;

            tree.add(a[i], -1);
            tree.add(a[(i + k) % n], 1);
        }

        if (first > n) cout << "0\n";
        else {
            memo.assign(2, vector<llong>(n + 5, -1LL));

            int dist = pos[0][first];
            if (n - dist < dist) dist = n - dist;

            llong ans = shifts(false, first) + dist;

            dist = pos[1][first];
            if (n - dist < dist) dist = n - dist;

            ans = min(ans, shifts(true, first) + dist);
            cout << ans << "\n";
        }
    }
}