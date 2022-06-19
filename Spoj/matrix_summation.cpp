#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int m, n;
    vector<vector<long>> tree;

public:
    FenwickTree(int m, int n) {
        this->m = m + 1;
        this->n = n + 1;
        tree.assign(m + 1, vector<long>(n + 1, 0LL));
    }

    void add(int i, int j, int v) {
        while (i < m) {
            int k = j;
            while (k < n) {
                tree[i][k] += v;
                k += LSO(k);
            }

            i += LSO(i);
        }
    }

    long sum(int i1, int j1, int i2, int j2) {
        return sum(i2, j2) - sum(i2, j1 - 1) - sum(i1 - 1, j2) + sum(i1 - 1, j1 - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long sum(int i, int j) {
        if (!i || !j) return 0LL;

        long ans = 0LL;
        while (i) {
            int k = j;
            while (k) {
                ans += tree[i][k];
                k -= LSO(k);
            }

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
        int N; cin >> N;

        string op;
        FenwickTree tree(N, N);
        vector<vector<long>> A(N, vector<long>(N, 0));

        while (cin >> op, op != "END") {
            if (op == "SET") {
                int x, y, num;
                cin >> x >> y >> num;

                tree.add(x + 1, y + 1, -A[x][y]);
                tree.add(x + 1, y + 1, num);
                A[x][y] = num;
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                long ans = tree.sum(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
                cout << ans << "\n";
            }
        }
    }
}