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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> order = a;
        sort(order.begin(), order.end());

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(order.begin(), order.end(), a[i]) - order.begin();
            a[i] = idx;
        }

        llong ans = 0LL;
        vector<int> ranges(n);

        for (int i = 0; i + 1 < n; i++) {
            int cnt = 0;
            FenwickTree tree(n);

            for (int j = i; j < n; j++) {
                int pos = tree.sum(0, a[j]);
                tree.add(a[j], 1);

                int idx = lower_bound(ranges.begin(), ranges.begin() + cnt, pos + 1) - ranges.begin();
                if (idx >= cnt) {
                    int prev = cnt ? ranges[cnt - 1] : 0;
                    ranges[cnt++] = prev + 1;
                } else {
                    int prev = idx ? ranges[idx - 1] : 0;
                    ranges[idx] = j - i + 1;
                    cnt = idx + 1;
                }

                ans += j - i + 1 - cnt;
            }
        }

        cout << ans << "\n";
    }
}