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

    int N; cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];

    vector<int> pos(N);
    for (int i = 0; i < N; i++)
        pos[P[i] - 1] = i;

    int best_K = -1;
    llong best_cost = LLONG_MAX;

    for (int i = 1; i <= N / 2; i++)
        if (N % i == 0) {
            llong X = 0LL;
            FenwickTree tree(N);

            for (int j = 0; j < N; j += i) {
                vector<int> ordered;
                for (int k = 0; k < i; k++)
                    ordered.push_back(pos[j + k]);

                sort(ordered.begin(), ordered.end());

                for (int k = 0; k < i; k++) {
                    int npos = ordered[k] + tree.sum(ordered[k], N - 1);
                    tree.add(ordered[k], 1);
                    X += npos - j - k;
                }
            }

            if (i * X < best_cost) {
                best_K = i;
                best_cost = i * X;
            }
        }

    cout << best_K << " " << best_cost << "\n";
}