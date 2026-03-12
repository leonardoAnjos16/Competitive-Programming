#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct BinaryLifting {
private:
    int n;
    vector<vector<int>> up;

public:
    BinaryLifting(int n, vector<int> &f) {
        this->n = n;

        up.assign(LOG, vector<int>(n));
        for (int i = 0; i < n; i++)
            up[0][i] = f[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++)
                up[i][j] = up[i - 1][up[i - 1][j]];
    }

    int count(int start, int goal) {
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int last = get_next(start, mid);

            if (last - start < goal) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        return ans;
    }

private:
    int get_next(int start, int jump) {
        int ans = start;
        for (int i = 0; i < LOG; i++)
            if (jump & (1 << i))
                ans = up[i][ans];

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    vector<llong> psd(2 * n + 1, 0LL);
    for (int i = 1; i <= 2 * n; i++)
        psd[i] = psd[i - 1] + d[(i - 1) % n];

    vector<int> nxt(2 * n + 2, 2 * n + 1);
    for (int i = 2 * n; i > 0; i--) {
        int l = i, r = 2 * n;
        while (l <= r) {
            int mid = (l + r) / 2;
            llong sum = psd[mid] - psd[i - 1];

            if (sum < c) l = mid + 1;
            else r = mid - 1, nxt[i] = mid + 1;
        }
    }

    BinaryLifting solver(2 * n + 2, nxt);
    for (int i = 1; i <= n; i++) {
        int ans = solver.count(i, n) - 1;

        if (i > 1) cout << " ";
        cout << ans;
    }

    cout << "\n";
}