#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        clear();
    }

    void clear() {
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

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i > 0) {
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

    vector<int> p(n);
    FenwickTree tree(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        tree.add(p[i], 1);
        p[i] = p[i] - tree.sum(0, p[i]) + 1;
    }

    vector<int> q(n);
    tree.clear();

    for (int i = 0; i < n; i++) {
        cin >> q[i];
        tree.add(q[i], 1);
        q[i] = q[i] - tree.sum(0, q[i]) + 1;
    }

    vector<int> sum(n);
    for (int i = 0; i < n; i++)
        sum[i] = p[i] + q[i];

    for (int i = 1; i < n; i++) {
        sum[n - i - 1] += sum[n - i] / i;
        sum[n - i] %= i;
    }

    sum[0] %= n;
    tree.clear();

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int zeroes = mid + 1 - tree.sum(0, mid);
            if (zeroes < sum[i] + 1) l = mid + 1;
            else r = mid - 1, ans[i] = mid;
        }

        tree.add(ans[i], 1);
    }

    for (auto i: ans)
        cout << i << " ";

    cout << "\n";
}