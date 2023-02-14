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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M; cin >> M;

    vector<llong> nums(1, 0);
    vector<pair<llong, llong>> ops(M);

    vector<int> updated(M);
    for (int i = 0; i < M; i++)
        updated[i] = i;

    for (int i = 0; i < M; i++) {
        int type; cin >> type;
        if (type == 1) {
            int A; cin >> A;
            nums.push_back(A);
            ops[i] = make_pair(A, A);
        } else if (type == 2) {
            int B; cin >> B;
            ops[i] = make_pair(ops[updated[B - 1]].second, 0LL);
        } else if (type == 3) {
            int B, A;
            cin >> B >> A;

            nums.push_back(ops[updated[B - 1]].second + A);
            ops[i] = make_pair(ops[updated[B - 1]].second, ops[updated[B - 1]].second + A);
            updated[B - 1] = i;
        } else {
            int B; cin >> B;
            ops[i] = make_pair(-1LL, ops[updated[B - 1]].second);
        }
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int size = nums.size();
    FenwickTree tree(size);

    for (int i = 0; i < M; i++) {
        auto [a, b] = ops[i];
        if (a == -1LL) {
            int idx = lower_bound(nums.begin(), nums.end(), b) - nums.begin();
            int ans = tree.sum(1, idx - 1);
            cout << ans << "\n";
        } else if (a == b) {
            int idx = lower_bound(nums.begin(), nums.end(), a) - nums.begin();
            tree.add(idx, 1);
        } else {
            int i1 = lower_bound(nums.begin(), nums.end(), a) - nums.begin();
            int i2 = lower_bound(nums.begin(), nums.end(), b) - nums.begin();

            tree.add(i1, -1);
            tree.add(i2, 1);
        }
    }
}