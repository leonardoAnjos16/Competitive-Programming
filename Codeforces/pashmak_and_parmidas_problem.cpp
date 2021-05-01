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
    int tree[MAX];

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

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i &-i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int sum = 0;
        while (i) {
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
    FenwickTree tree;

    int a[MAX];
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tree.add(++cnt[a[i]], 1);
    }

    long ans = 0LL;
    map<int, int> seen;

    for (int i = 0; i < n; i++) {
        tree.add(cnt[a[i]] - seen[a[i]], -1);
        ans += tree.sum(0, seen[a[i]]++);
    }

    cout << ans << "\n";
}