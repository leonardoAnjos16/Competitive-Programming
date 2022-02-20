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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n), numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            numbers[i] = a[i];
        }

        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

        bool possible = true;
        int size = numbers.size();
        FenwickTree cnt(size), odd(size);

        for (int i = 0; i < n && possible; i++) {
            bool is_odd = a[i] & 1;
            int idx = lower_bound(numbers.begin(), numbers.end(), a[i]) - numbers.begin();

            if (is_odd && odd.sum(idx + 1, size)) possible = false;
            else if (!is_odd && cnt.sum(idx + 1, size) > odd.sum(idx + 1, size)) possible = false;

            cnt.add(idx, 1);
            if (is_odd)
                odd.add(idx, 1);
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
}