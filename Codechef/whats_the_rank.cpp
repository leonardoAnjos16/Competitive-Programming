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

    int N; cin >> N;

    vector<int> merchants(N), sorted(N);
    for (int i = 0; i < N; i++) {
        cin >> merchants[i];
        sorted[i] = merchants[i];
    }

    sort(sorted.begin(), sorted.end());

    FenwickTree tree(N);
    for (auto m: merchants) {
        int idx = lower_bound(sorted.begin(), sorted.end(), m) - sorted.begin();

        int ans = tree.sum(idx + 1, N) + 1;
        cout << ans << "\n";

        tree.add(idx + 1, 1);
    }
}