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

    int N, K;
    cin >> N >> K;

    long sum = 0LL;
    vector<long> sums(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        sum += a;
        sums[i] = sum - 1LL * K * i;
    }

    vector<long> sorted = sums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    int size = sorted.size();
    FenwickTree tree(size);

    long ans = 0LL;
    for (int i = 0; i <= N; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), sums[i]) - sorted.begin();
        ans += tree.query(0, idx);
        tree.add(idx, 1);
    }

    cout << ans << "\n";
}