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

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> ys(n);
    vector<tuple<int, int, int>> ranges(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        ys[i] = y;
        ranges[i] = make_tuple(x, y, i);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(ranges.begin(), ranges.end());

    vector<int> equal(n, 1);
    for (int i = 1; i < n; i++)
        if (get<0>(ranges[i]) == get<0>(ranges[i - 1]))
            equal[i] = equal[i - 1] + 1;

    int size = ys.size();
    FenwickTree tree(size);
    vector<int> contains(n);

    for (int i = n - 1; i >= 0; i--) {
        auto [x, y, idx] = ranges[i];

        auto it = lower_bound(ys.begin(), ys.end(), y);
        contains[idx] = tree.sum(0, it - ys.begin()) + equal[i] - 1;

        tree.add(it - ys.begin(), 1);
    }

    equal.assign(n, 1);
    for (int i = n - 2; i >= 0; i--)
        if (get<0>(ranges[i]) == get<0>(ranges[i + 1]))
            equal[i] = equal[i + 1] + 1;

    tree = FenwickTree(size);
    vector<int> contained(n);

    for (int i = 0; i < n; i++) {
        auto [x, y, idx] = ranges[i];

        auto it = lower_bound(ys.begin(), ys.end(), y);
        contained[idx] = tree.sum(it - ys.begin(), size - 1) + equal[i] - 1;

        tree.add(it - ys.begin(), 1);
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << contains[i];
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << contained[i];
    }

    cout << "\n";
}