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

    int n, q;
    cin >> n >> q;

    FenwickTree tree(n);
    while (q--) {
        char op; cin >> op;
        if (op == '-') {
            int a; cin >> a;
            tree.add(a - 1, 1);
        } else if (op == '+') {
            int a; cin >> a;
            tree.add(a - 1, -1);
        } else {
            int a, b;
            cin >> a >> b;

            if (a > b) swap(a, b);

            if (!tree.sum(a - 1, b - 1)) cout << "possible\n";
            else if (!tree.sum(0, a - 1) && !tree.sum(b - 1, n - 1)) cout << "possible\n";
            else cout << "impossible\n";
        }
    }
}