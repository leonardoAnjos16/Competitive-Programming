#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int SQRT = 350;

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

    int N, K, Q;
    cin >> N >> K >> Q;

    llong invs = 0LL;
    FenwickTree tree(K);
    vector<vector<int>> pos(K + 1, vector<int>());

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        pos[a].push_back(i);

        invs += tree.sum(a + 1, K);
        tree.add(a, 1);
    }

    vector<int> heavy, idx(K + 1, -1);
    for (int i = 1; i <= K; i++)
        if ((int) pos[i].size() > SQRT) {
            idx[i] = heavy.size();
            heavy.push_back(i);
        }

    int size = heavy.size();
    vector<vector<llong>> diff(size, vector<llong>(size, 0LL));

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (i == j) continue;

            int idx = 0;
            for (int k = 0; k < (int) pos[heavy[i]].size(); k++) {
                while (idx < (int) pos[heavy[j]].size() && pos[heavy[j]][idx] < pos[heavy[i]][k]) idx++;
                diff[i][j] += (int) pos[heavy[j]].size() - 2 * idx;
            }
        }

    vector<int> id(K + 1);
    for (int i = 1; i <= K; i++)
        id[i] = i;

    vector<map<int, llong>> memo(K + 1);
    while (Q--) {
        int i; cin >> i;

        llong d = 0LL;
        if (memo[id[i]].count(id[i + 1])) d = memo[id[i]][id[i + 1]];
        else if (idx[id[i]] != -1 && idx[id[i + 1]] != -1) d = diff[idx[id[i]]][idx[id[i + 1]]];
        else if (idx[id[i]] == -1 && idx[id[i + 1]] == -1) {
            int j = id[i], k = id[i + 1], idx = 0;
            for (int l = 0; l < (int) pos[j].size(); l++) {
                while (idx < (int) pos[k].size() && pos[k][idx] < pos[j][l]) idx++;
                d += (int) pos[k].size() - 2 * idx;
            }
        }
        else {
            bool swapped = false;
            int j = id[i], k = id[i + 1];

            if (idx[j] != -1) {
                swap(j, k);
                swapped = true;
            }

            for (int p: pos[j]) {
                int idx = upper_bound(pos[k].begin(), pos[k].end(), p) - pos[k].begin();
                if (!swapped) d += (int) pos[k].size() - 2 * idx;
                else d -= (int) pos[k].size() - 2 * idx;
            }
        }

        invs += d;
        cout << invs << "\n";

        memo[id[i]][id[i + 1]] = d;
        swap(id[i], id[i + 1]);
    }
}