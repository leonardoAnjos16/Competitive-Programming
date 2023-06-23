#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<int> cnt;
    vector<llong> sum;

public:
    SegmentTree(int n) {
        this->n = n;
        cnt.assign(4 * n, 0);
        sum.assign(4 * n, 0LL);
    }

    void update(int i, int c, int v) {
        update(1, 1, n, i, c, v);
    }

    llong query(int k) {
        return query(1, 1, n, k);
    }

private:
    void update(int node, int l, int r, int i, int c, int v) {
        if (l == r) {
            cnt[node] += c;
            sum[node] += v;
        } else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, c, v);
            else update(2 * node + 1, m + 1, r, i, c, v);

            cnt[node] = cnt[2 * node] + cnt[2 * node + 1];
            sum[node] = sum[2 * node] + sum[2 * node + 1];
        }
    }

    llong query(int node, int l, int r, int k) {
        if (l == r) {
            assert(cnt[node] >= k);
            return k * sum[node] / cnt[node];
        }

        int m = (l + r) / 2;
        if (cnt[2 * node + 1] >= k) return query(2 * node + 1, m + 1, r, k);
        return sum[2 * node + 1] + query(2 * node, l, m, k - cnt[2 * node + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int K, L;
    cin >> K >> L;

    vector<int> order = B;
    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());
    int sz = order.size();

    llong fsum = 0LL;
    SegmentTree tree(sz);

    for (int i = 0; i < K; i++) {
        fsum += A[i];

        int idx = lower_bound(order.begin(), order.end(), B[i]) - order.begin();
        tree.update(idx + 1, 1, B[i]);
    }

    llong ans = fsum + tree.query(L);
    for (int i = 1; i <= K; i++) {
        fsum -= A[K - i];
        fsum += A[N - i];

        int idx = lower_bound(order.begin(), order.end(), B[K - i]) - order.begin();
        tree.update(idx + 1, -1, -B[K - i]);

        idx = lower_bound(order.begin(), order.end(), B[N - i]) - order.begin();
        tree.update(idx + 1, 1, B[N - i]);

        ans = max(ans, fsum + tree.query(L));
    }

    cout << ans << "\n";
}