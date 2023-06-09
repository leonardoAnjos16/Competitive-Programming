#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void update(int i, int v) {
        if (!i) tree[i] = max(tree[i], v);
        else {
            while (i < n) {
                tree[i] = max(tree[i], v);
                i += LSO(i);
            }
        }
    }

    int maximum(int i) {
        int ans = tree[0];
        while (i) {
            ans = max(ans, tree[i]);
            i -= LSO(i);
        }

        return ans;
    }

private:
    int LSO(int i) {
        return i & -i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int xh, yh, xw, yw;
    cin >> xh >> yh >> xw >> yw;

    vector<int> ys;
    vector<pair<int, int>> errands(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (xw < xh) x = 2 * xh - x;
        if (yw < yh) y = 2 * yh - y;

        ys.push_back(y);
        errands[i] = make_pair(x, y);
    }

    if (xw < xh) xw = 2 * xh - xw;
    if (yw < yh) yw = 2 * yh - yw;

    sort(errands.begin(), errands.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int sz = ys.size();
    FenwickTree tree(sz);

    int ans = 0;
    for (auto [x, y]: errands) {
        if (x < xh || x > xw || y < yh || y > yw) continue;

        int idx = lower_bound(ys.begin(), ys.end(), y) - ys.begin();

        int lnds = tree.maximum(idx);
        tree.update(idx, lnds + 1);
        ans = max(ans, lnds + 1);
    }

    cout << ans << "\n";
}