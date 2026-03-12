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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> choice(N);
    for (int i = 0; i < N; i++) {
        if (i < N / 2) cin >> choice[2 * i];
        else cin >> choice[2 * (i - N / 2) + 1];
    }

    FenwickTree tree(N);
    for (int i = 0; i < N; i++)
        tree.add(i, 1);

    vector<int> first, second;
    for (int i = 0; i < N; i++) {
        int l = 0, r = N - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (tree.sum(0, mid) < choice[i]) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        assert(ans != -1);
        tree.add(ans++, -1);

        if (i & 1) second.push_back(ans);
        else first.push_back(ans);
    }

    for (int i = 0; i < N / 2; i++) {
        if (i) cout << " ";
        cout << first[i];
    }

    cout << "\n";
    for (int i = 0; i < N / 2; i++) {
        if (i) cout << " ";
        cout << second[i];
    }

    cout << "\n";
}