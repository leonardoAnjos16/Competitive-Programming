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

struct BIT {
private:
    int tree[MAX];

public:
    BIT() {
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

    int RSQ(int l, int r) {
        return RSQ(r) - RSQ(l - 1);
    }

private:
    int LSO(int n) {
        return n & -n;
    }

    int RSQ(int i) {
        if (i < 0) return 0;

        int sum = 0;
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

    int n; cin >> n;

    BIT tree;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;

        int ans = n - tree.RSQ(s, MAX - 1);
        cout << ans << "\n";

        tree.add(s, 1);
    }
}