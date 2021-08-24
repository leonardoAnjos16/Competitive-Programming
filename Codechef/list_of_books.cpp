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

    int M; cin >> M;

    vector<int> books(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> books[i];

    FenwickTree tree(M);

    int N; cin >> N;
    while (N--) {
        int idx; cin >> idx;

        int l = 1, r = M, aux = 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (mid - tree.sum(1, mid) >= idx) r = mid - 1;
            else l = mid + 1, aux = mid + 1;
        }

        int ans = books[aux];
        cout << ans << "\n";

        tree.add(aux, 1);
    }
}