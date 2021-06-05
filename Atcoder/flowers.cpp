#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int n;
    vector<long> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0LL);
    }

    void update(int i, long x) {
        if (!i) tree[0] = max(tree[0], x);
        else {
            while (i < n) {
                tree[i] = max(tree[i], x);
                i += LSO(i);
            }
        }
    }

    long query(int i) {
        if (i < 0) return 0LL;

        long ans = 0LL;
        while (i > 0) {
            ans = max(ans, tree[i]);
            i -= LSO(i);
        }

        return max(ans, tree[0]);
    }

private:
    int LSO(int i) {
        return i & -i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    FenwickTree tree(N);
    vector<long> LISS(N, 0LL);

    long ans = 0LL;
    for (int i = 0; i < N; i++) {
        LISS[i] = tree.query(h[i]) + a[i];
        tree.update(h[i], LISS[i]);
        ans = max(ans, LISS[i]);
    }

    cout << ans << "\n";
}