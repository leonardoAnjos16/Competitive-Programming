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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), numbers(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        numbers[i] = a[i];
    }

    numbers[n] = k;
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    int size = numbers.size();
    FenwickTree cnt(size), ones(size);
    vector<int> seen(size, 0);

    long ans = 0LL;
    int k_pos = lower_bound(numbers.begin(), numbers.end(), k) - numbers.begin();

    for (int i = 0; i <= n; i++) {
        if (i >= m) {
            int l = k_pos, r = size - 1, aux = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ones.sum(k_pos, mid) < numbers[mid] - k + 1) r = mid - 1;
                else l = mid + 1, aux = mid;
            }

            if (aux != -1) {
                int diff = numbers[aux] - k + 1;
                aux = upper_bound(numbers.begin(), numbers.end(), diff) - numbers.begin();
                if (aux) ans += cnt.sum(0, aux - 1);
            }

            int idx = lower_bound(numbers.begin(), numbers.end(), a[i - m]) - numbers.begin();
            cnt.add(idx, -1);

            seen[idx]--;
            if (!seen[idx])
                ones.add(idx, -1);
        }

        if (i < n) {
            int idx = lower_bound(numbers.begin(), numbers.end(), a[i]) - numbers.begin();
            cnt.add(idx, 1);

            seen[idx]++;
            if (!(seen[idx] - 1))
                ones.add(idx, 1);
        }
    }

    cout << ans << "\n";
}