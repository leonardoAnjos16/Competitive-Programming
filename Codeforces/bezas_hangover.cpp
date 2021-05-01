#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

struct FenwickTree {
private:
    vi tree;
    int n;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i < n) {
                tree[i] += x;
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

        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans + tree[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;

    string D[MAX];
    for (int i = 0; i < N; i++)
        cin >> D[i];

    map<string, int> liters;
    for (int i = 0; i < M; i++) {
        string S; int V;
        cin >> S >> V;
        liters[S] = V;
    }

    FenwickTree tree(N);
    for (int i = 0; i < N; i++)
        tree.add(i + 1, liters[D[i]]);

    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int X; string Y;
            cin >> X >> Y;

            tree.add(X, liters[Y] - liters[D[X - 1]]);
            D[X - 1] = Y;
        } else {
            int L, R;
            cin >> L >> R;

            int sum = tree.sum(L, R);
            cout << (sum > 30 * (R - L + 1) ? "YES" : "NO") << "\n";
        }
    }
}