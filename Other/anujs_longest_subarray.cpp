#include <bits/stdc++.h>

using namespace std;

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

pair<vector<vector<int>>, vector<vector<int>>> first_k_greater(vector<int> &a, int n, int k) {
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[a[i] - 1] = i;

    FenwickTree tree(n);
    vector<vector<int>> left(n, vector<int>(k, -1));
    vector<vector<int>> right(n, vector<int>(k, -1));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            int l = pos[i], r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tree.sum(pos[i], mid) > j) r = mid - 1;
                else l = mid + 1, right[pos[i]][j] = mid;
            }

            l = 0; r = pos[i];
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tree.sum(mid, pos[i]) > j) l = mid + 1;
                else r = mid - 1, left[pos[i]][j] = mid;
            }
        }

        tree.add(pos[i], 1);
    }

    return make_pair(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        auto [left_first_k_greater, right_first_k_greater] = first_k_greater(a, n, k);
        for (int i = 0; i < n; i++) {
            int ans = 1;
            for (int j = 0; j < k; j++) {
                int begin = left_first_k_greater[i][j];
                int end = right_first_k_greater[i][k - j - 1];

                if (end == -1) end = n - 1;
                ans = max(ans, end - begin + 1);
            }

            if (i) cout << " ";
            cout << ans;
        }

        cout << "\n";
    }
}