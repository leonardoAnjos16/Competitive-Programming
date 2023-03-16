#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct SparseTable {
private:
    vector<vector<int>> mn, mx;

public:
    SparseTable(int n, vector<int> &a) {
        mn.assign(LOG, vector<int>(n));
        mx.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            mn[0][i] = mx[0][i] = a[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++) {
                mn[i][j] = mn[i - 1][j];
                mx[i][j] = mx[i - 1][j];

                int jump = 1 << (i - 1);
                if (j + jump < n) {
                    mn[i][j] = min(mn[i][j], mn[i - 1][j + jump]);
                    mx[i][j] = max(mx[i][j], mx[i - 1][j + jump]);
                }
            }
    }

    pair<int, int> query(int l, int r) {
        int idx = __lg(r - l + 1), jump = 1 << idx;
        int first = min(mn[idx][l], mn[idx][r - jump + 1]);
        int second = max(mx[idx][l], mx[idx][r - jump + 1]);
        return make_pair(first, second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("milk.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N + 1, 0);
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        SparseTable table(N + 1, A);
        while (Q--) {
            int U, V;
            cin >> U >> V;

            if (U == V) cout << (table.query(0, N).second >= U ? "Yes" : "No") << "\n";
            else {
                int l = 0, r = N, first = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (U < V && table.query(0, mid).first > U) l = mid + 1;
                    else if (U > V && table.query(0, mid).second < U) l = mid + 1;
                    else r = mid - 1, first = mid;
                }

                l = 0; r = N;
                int last = -1;

                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (U < V && table.query(mid, N).second < V) r = mid - 1;
                    else if (U > V && table.query(mid, N).first > V) r = mid - 1;
                    else l = mid + 1, last = mid;
                }

                if (first == -1 || last == -1) cout << "No\n";
                else cout << (first < last ? "Yes" : "No") << "\n";
            }
        }
    }
}