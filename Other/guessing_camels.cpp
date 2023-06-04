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
        if (!i) tree[i] += v;
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

llong inversions(vector<int> &a) {
    int n = a.size();

    llong ans = 0LL;
    FenwickTree tree(n);

    for (int i = 0; i < n; i++) {
        ans += tree.sum(a[i], n);
        tree.add(a[i], 1);
    }

    return ans;
}

llong inversions(vector<int> &a, vector<int> &b) {
    int n = a.size();

    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[a[i] - 1] = i;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[i] = pos[b[i] - 1];

    return inversions(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    llong invs = inversions(a, b);
    invs += inversions(a, c);
    invs += inversions(b, c);
    invs /= 2LL;

    llong ans = n * (n - 1LL) / 2LL - invs;
    cout << ans << "\n";
}