#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e7 + 5;

struct FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(): tree(MAX, 0) {}

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < MAX) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int query(int i) {
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        long ans = 0LL;
        FenwickTree tree;

        for (int i = 0; i < n; i++) {
            int A; cin >> A;

            ans += tree.query(A + 1, MAX - 1);
            tree.add(A, 1);
        }

        cout << ans << "\n";
    }
}