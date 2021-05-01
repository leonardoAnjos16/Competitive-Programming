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

const int MAX = 1e6 + 5;

struct FenwickTree {
private:
    long tree[MAX];

public:
    FenwickTree() {
        memset(tree, 0, sizeof tree);
    }

    void add(int i, int x) {
        if (!i) tree[0] += x;
        else {
            while (i < MAX) {
                tree[i] += x;
                i += LSO(i);
            }
        }
    }

    long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long sum(int i) {
        if (i < 0) return 0;

        long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= LSO(i);
        }

        return sum + tree[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        FenwickTree tree;

        long ans = 0LL;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            ans += tree.sum(0, a - 1);
            tree.add(a, a);
        }

        cout << ans << "\n";
    }
}