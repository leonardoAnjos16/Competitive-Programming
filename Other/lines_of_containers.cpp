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

    void clear() {
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

    int L, C;
    cin >> L >> C;

    vector<vector<int>> X(L, vector<int>(C));
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            cin >> X[i][j];

    /* int ans = 0;
    FenwickTree tree(L * C);

    for (int i = 0; i < C; i++) {
        ans += tree.sum(X[0][i] + 1, L * C);
        tree.add(X[0][i], 1);
    } */

    int ans = 0;
    for (int i = 0; i < C; i++) {
        int idx = i;
        for (int j = i + 1; j < C; j++)
            if (X[0][j] < X[0][idx])
                idx = j;

        for (int j = 0; j < L; j++)
            swap(X[j][i], X[j][idx]);

        ans += i != idx;
    }

    for (int i = 0; i < L; i++) {
        int idx = i;
        for (int j = i + 1; j < L; j++)
            if (X[j][0] < X[idx][0])
                idx = j;

        for (int j = 0; j < C; j++)
            swap(X[i][j], X[idx][j]);

        ans += i != idx;
    }

    int cnt = 1;
    bool possible = true;

    for (int i = 0; i < L && possible; i++)
        for (int j = 0; j < C && possible; j++)
            if (X[i][j] != cnt++) possible = false;

    if (!possible) cout << "*\n";
    else cout << ans << "\n";
}