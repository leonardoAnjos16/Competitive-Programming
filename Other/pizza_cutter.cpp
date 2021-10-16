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

    int X, Y;
    cin >> X >> Y;

    int H, V;
    cin >> H >> V;

    vector<int> ys;
    vector<pair<int, int>> horizontal(H);

    for (int i = 0; i < H; i++) {
        int Y1, Y2;
        cin >> Y1 >> Y2;

        ys.push_back(Y2);
        horizontal[i] = make_pair(Y1, Y2);
    }

    vector<int> xs;
    vector<pair<int, int>> vertical(V);

    for (int i = 0; i < V; i++) {
        int X1, X2;
        cin >> X1 >> X2;

        xs.push_back(X2);
        vertical[i] = make_pair(X1, X2);
    }

    sort(ys.begin(), ys.end());
    sort(horizontal.begin(), horizontal.end());

    sort(xs.begin(), xs.end());
    sort(vertical.begin(), vertical.end());

    int n = xs.size();
    int m = ys.size();

    long ans = 1LL;

    {
        FenwickTree tree(m);
        for (int i = 0; i < H; i++) {
            int idx = lower_bound(ys.begin(), ys.end(), horizontal[i].second) - ys.begin();
            ans += tree.sum(idx + 1, m) + 1LL;
            tree.add(idx, 1);
        }
    }

    {
        FenwickTree tree(n);
        for (int i = 0; i < V; i++) {
            int idx = lower_bound(xs.begin(), xs.end(), vertical[i].second) - xs.begin();
            ans += tree.sum(idx + 1, n) + H + 1LL;
            tree.add(idx, 1);
        }
    }

    cout << ans << "\n";
}