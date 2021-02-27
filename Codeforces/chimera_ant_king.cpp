#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 50;

int n, v[MAX], r[10][10];
int row_used[10] = {0}, col_used[10] = {0}, block_used[10] = {0}, region_used[MAX] = {0};
int ans[10][10], sums[MAX] = {0};
bool done = false;

void solve(int i = 0, int j = 0) {
    if (done) return;
    if (i >= 6) {
        done = true;
        for (int i = 0; i < n; i++)
            if (sums[i] != v[i]) done = false;

        return;
    }

    if (j >= 6) solve(i + 1);
    else {
        for (int k = 1; k <= 6 && !done; k++) {
            int block = 2 * (i / 2) + j / 3;
            if (!(row_used[i] & (1 << k)) &&
                !(col_used[j] & (1 << k)) &&
                !(block_used[block] & (1 << k)) &&
                !(region_used[r[i][j] - 1] & (1 << k)) &&
                sums[r[i][j] - 1] + k <= v[r[i][j] - 1]) {
                    ans[i][j] = k;
                    row_used[i] |= (1 << k);
                    col_used[j] |= (1 << k);
                    block_used[block] |= (1 << k);
                    region_used[r[i][j] - 1] |= (1 << k);
                    sums[r[i][j] - 1] += k;

                    solve(i, j + 1);

                    if (!done) ans[i][j] = 0;
                    row_used[i] ^= (1 << k);
                    col_used[j] ^= (1 << k);
                    block_used[block] ^= (1 << k);
                    region_used[r[i][j] - 1] ^= (1 << k);
                    sums[r[i][j] - 1] -= k;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> r[i][j];

    solve();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << ans[i][j] << " ";

        cout << "\n";
    }
}